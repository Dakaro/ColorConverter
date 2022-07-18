#include <windows.h>
#include "MainLabel.hpp"

LPSTR NazwaKlasy = "WindowClass";
MSG Komunikat;

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

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
    wc.lpszClassName = NazwaKlasy;
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


    HMENU hMenu = LoadMenu( hInstance, MAKEINTRESOURCE( 200 ) );

    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "Image Color Converter", WS_OVERLAPPEDWINDOW,
                           CW_USEDEFAULT, CW_USEDEFAULT, 1024, 512, NULL, hMenu, hInstance, NULL );
    MainLabel mainLabel(hwnd, hInstance);

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
    }
    return Komunikat.wParam;
}

// EVENTS MANAGING
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_CLOSE:
            DestroyWindow( hwnd );
            break;

        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;

        default:
            return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}
