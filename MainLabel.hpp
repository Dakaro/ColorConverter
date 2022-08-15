#ifndef UNTITLED4_MAINLABEL_HPP
#define UNTITLED4_MAINLABEL_HPP

#include <windows.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "ChangeColor.hpp"

#define  ID_BUTTON_RUN 501
#define ID_BUTTON_SHOWIMAGE 502


    void MainLabel(HWND hwnd, HINSTANCE hInstance);
    std::string OpenFileDialog(HWND hwnd);
    std::string SaveFileDialog(HWND hwnd);
    void addShapeToRender(ChangeColor &sprite);
    void renderView();
    void runSFMLWindow();
    void closeSFMLWindow();
    void showImage();
    bool isImageActive();
    int comboBoxMode();
    void enableImage(bool state);
#endif //UNTITLED4_MAINLABEL_HPP
