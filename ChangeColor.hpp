#ifndef COLORCONVERTER_CHANGECOLOR_HPP
#define COLORCONVERTER_CHANGECOLOR_HPP

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <cstring>

class ChangeColor{
private:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite tempSprite;

public:
    sf::Image getImage();
    sf::Sprite getSprite();
    void setImageStr(std::string imageStr);
    ChangeColor();
     ~ChangeColor();
    void convertGreen();
    void convertUV();
    void convertLight();
    void convertBlackWhite();
    void saveImage(std::string fileStr);
};

sf::Color getColor(sf::Color color);
sf::Color lowBits(sf::Color color);
sf::Color uvLampColor(sf::Color color);
sf::Color lightColor(sf::Color color);




#endif //COLORCONVERTER_CHANGECOLOR_HPP
