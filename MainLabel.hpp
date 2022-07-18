#ifndef UNTITLED4_MAINLABEL_HPP
#define UNTITLED4_MAINLABEL_HPP

#include <windows.h>

class MainLabel {
public:
    HWND hComboStyles;
    HWND hRunButton;
    HWND staticMenuDesc;

    MainLabel(HWND hwnd, HINSTANCE hInstance);
    void loadLabel();
    ~MainLabel();



};


#endif //UNTITLED4_MAINLABEL_HPP
