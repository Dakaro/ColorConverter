#include <windows.h>
#include "MainLabel.hpp"
#include <string>
#include "ChangeColor.hpp"

#define ID_BUTTON_OPEN 101
#define ID_BUTTON_SAVE 102


LPSTR MainClass = "WindowClass";
MSG Komunikat;
std::string fileStr = "NULL";
ChangeColor colorMode;
void (ChangeColor::*convertMode)();
HMENU hMenu;



LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

void controlsState(HWND hwnd){
    if( isImageActive() || fileStr == "NULL" ){
        EnableWindow(GetDlgItem(hwnd , ID_BUTTON_SHOWIMAGE), false);
    }
    else {
        EnableWindow(GetDlgItem(hwnd , ID_BUTTON_SHOWIMAGE), true);
    }

    if( comboBoxMode() != CB_ERR && isImageActive() ){
        EnableWindow(GetDlgItem(hwnd , ID_BUTTON_RUN), true);
    }

    switch( comboBoxMode() ){
        case 0: { //GREEN
            convertMode = &ChangeColor::convertGreen;
            break;
        }

        case 1: {// MARIO
            convertMode = &ChangeColor::convertMario;
            break;
        }

        case 2: {// BUBBLE GUM
            convertMode = &ChangeColor::convertBubbleGum;
            break;
        }

        case 3: { // BLACK WHITE
            convertMode = &ChangeColor::convertBlackWhite;
            break;
        }

    }

}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

    // CREATE STRUCTURE
    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = MainClass;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );



    // WINDOW REGISTRATION
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, "We cannot open your window", "What a pity!",
                    MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }

    // WINDOWN CREATING
    HWND hwnd;


    hMenu = LoadMenu( hInstance, MAKEINTRESOURCE( 200 ) );

    hwnd = CreateWindowEx( WS_EX_WINDOWEDGE, MainClass, "Image Color Converter", WS_TILED | WS_SYSMENU,
                           CW_USEDEFAULT, CW_USEDEFAULT, 200, 512, NULL, hMenu, hInstance, NULL );


    MainLabel(hwnd, hInstance);

    if( hwnd == NULL )
    {
        MessageBox( NULL, "Window doesn't want to show", "Oh no....", MB_ICONEXCLAMATION );
        return 1;
    }



    ShowWindow( hwnd, nCmdShow ); // show window
    UpdateWindow( hwnd );

    // Main Loop
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
        controlsState(hwnd);
        renderView();

    }
    return Komunikat.wParam;
}

// EVENTS MANAGING
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_COMMAND:
            switch(wParam)
            {
                case ID_BUTTON_OPEN: {
                    fileStr = OpenFileDialog(hwnd);
                    if( fileStr != "NULL" ) {
                        colorMode.setImageStr(fileStr);
                        addShapeToRender(colorMode);
                        showImage();
                        EnableMenuItem(hMenu, ID_BUTTON_SAVE, MF_ENABLED);
                    }
                    break;
                }

                case ID_BUTTON_SAVE: {
                    fileStr = SaveFileDialog(hwnd);
                    if ( fileStr != "NULL" ) {
                        colorMode.saveImage(fileStr);
                    }
                    break;
                }

                case ID_BUTTON_SHOWIMAGE: {
                    showImage();
                    break;
                }

                case ID_BUTTON_RUN: {
                    (colorMode.*convertMode)();
                    break;
                }
            }
            break;

        case WM_CLOSE:
            DestroyWindow( hwnd );
            closeSFMLWindow();
            break;

        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;

        default:
            return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}





