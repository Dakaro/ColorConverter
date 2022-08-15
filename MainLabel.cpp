#include "MainLabel.hpp"
#include <windows.h>
#include <iostream>
#include <cstdio>
#include <windowsx.h>

HWND hComboStyles;
HWND hRunButton;
HWND hShowImageButton;
HWND staticMenuDesc;
sf::RenderWindow SFMLRender;
sf::Sprite tempSprite;
bool showImageState = 0;

void renderView(){
    SFMLRender.clear();
    SFMLRender.draw(tempSprite);
    SFMLRender.display();

    sf::Event event;
    while(SFMLRender.pollEvent(event))
    {
        if(event.type == sf::Event::Closed) {
            closeSFMLWindow();
        }
    }
}

void addShapeToRender(ChangeColor &sprite){
    tempSprite = sprite.getSprite();
}

void scaleSprite(int &width, int &height){
    float widthScale = 1;
    float heightScale = 1;

    if( tempSprite.getLocalBounds().width > 800  ){
        widthScale = 1 / (tempSprite.getLocalBounds().width / 800);
        heightScale = widthScale;
    }

    if( tempSprite.getLocalBounds().height > 400 && widthScale == 1) {
        heightScale = 1 / (tempSprite.getLocalBounds().height / 400);
        widthScale = heightScale;
    }

    tempSprite.setScale(widthScale, heightScale);

    width = tempSprite.getLocalBounds().width * widthScale;
    height = tempSprite.getLocalBounds().height * heightScale;
}

void runSFMLWindow(){
    int width, height;
    scaleSprite(width, height);
   SFMLRender.create(sf::VideoMode(width, height),
                     "Image Render", sf::Style::Close);
}

void closeSFMLWindow(){
    showImageState = 0;
    SFMLRender.close();
}

void showImage(){
    showImageState = 1;
    runSFMLWindow();
}

void enableImage(bool state){
    showImageState = state;
}

int comboBoxMode(){
    return ComboBox_GetCurSel( hComboStyles );
}

bool isImageActive(){
    if( showImageState )
        return true;

    return false;
}


void MainLabel(HWND hwnd, HINSTANCE hInstance) {

    staticMenuDesc = CreateWindow( "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_CENTER ,
                                     0, 5, 200, 512, hwnd, NULL, hInstance, NULL );
    SetWindowText( staticMenuDesc, "MENU" );

    hRunButton =  CreateWindow(  "BUTTON", "Run", WS_CHILD | WS_VISIBLE | WS_DISABLED,
                                 30, 100, 140, 30, hwnd, (HMENU)ID_BUTTON_RUN, hInstance, NULL );

    hShowImageButton = CreateWindow(  "BUTTON", "Show Image", WS_CHILD | WS_VISIBLE | WS_DISABLED,
                                      30, 140, 140, 30, hwnd, (HMENU)ID_BUTTON_SHOWIMAGE, hInstance, NULL );


    hComboStyles = CreateWindow(  "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST,
                                  25, 50, 150, 200, hwnd, NULL, hInstance, NULL );

    SendMessage( hComboStyles, CB_ADDSTRING, 0,( LPARAM ) "Green Mode" );
    SendMessage( hComboStyles, CB_ADDSTRING, 0,( LPARAM ) "UV Mode" );
    SendMessage( hComboStyles, CB_ADDSTRING, 0,( LPARAM ) "Light Mode" );
    SendMessage( hComboStyles, CB_ADDSTRING, 0,( LPARAM ) "Black Mode" );
}

std::string OpenFileDialog(HWND hwnd){
    OPENFILENAME ofn;       // common dialog box structure
    char szFile[260];       // buffer for file name
    HANDLE hf;              // file handle

// Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;

    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All\0*.*\0png\0*.PNG\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

// Display the Open dialog box.

    if (GetOpenFileName(&ofn)==TRUE){
        std::cout << ofn.lpstrFile << std::endl;

        return ofn.lpstrFile;

    }

    return "NULL";
}

std::string SaveFileDialog(HWND hwnd){
    OPENFILENAME ofn;       // common dialog box structure
    char szFile[260];       // buffer for file name
    HANDLE hf;              // file handle

// Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;

    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All\0*.*\0png\0*.PNG\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

// Display the Open dialog box.

    if (GetSaveFileName(&ofn)==TRUE){
        std::cout << ofn.lpstrFile << std::endl;

        return ofn.lpstrFile;

    }

    return "NULL";
}