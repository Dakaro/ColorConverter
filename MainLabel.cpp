#include "MainLabel.hpp"
#include <windows.h>

MainLabel::MainLabel(HWND hwnd, HINSTANCE hInstance) {
    staticMenuDesc = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
                                                        SS_CENTER, 0, 0, 150, 200, hwnd, NULL, hInstance, NULL );
    SetWindowText( staticMenuDesc, "MENU" );

    hRunButton = CreateWindowEx( 0, "BUTTON", "Run", WS_CHILD | WS_VISIBLE,
                                 0, 70, 150, 30, hwnd, NULL, hInstance, NULL );


    hComboStyles = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
                                                                       CBS_DROPDOWNLIST, 0, 30, 150, 200, hwnd, NULL, hInstance, NULL );

    SendMessage( hComboStyles, CB_ADDSTRING, 0,( LPARAM ) "Element 1" );
    SendMessage( hComboStyles, CB_ADDSTRING, 0,( LPARAM ) "Element 2" );

}

void MainLabel::loadLabel() {



}

MainLabel::~MainLabel() {}