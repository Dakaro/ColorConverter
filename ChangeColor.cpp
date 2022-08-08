#include "ChangeColor.hpp"
#include <iostream>
#include <cmath>

ChangeColor::ChangeColor(){};

void ChangeColor::setImageStr(std::string imageStr) {
    this->image.loadFromFile(imageStr);
    this->texture.loadFromImage(image);
    tempSprite.setTexture(texture, 1);
}

ChangeColor::~ChangeColor(){}

sf::Image ChangeColor::getImage() {
    return image;
}

sf::Sprite ChangeColor::getSprite() {
    return tempSprite;
}

void ChangeColor::saveImage(std::string fileStr) {
    image.saveToFile(fileStr);
}

void ChangeColor::convertGreen() {

    sf::Color color;

    for( int i = 0;  i < texture.getSize().y; ++i ){
        for( int j = 0; j < texture.getSize().x; ++j ){
            color = sf::Color( 0, image.getPixel(j, i).g, 0);
            image.setPixel(j, i, color);
        }
    }

    texture.loadFromImage(image);
    tempSprite.setTexture(texture);

}

void ChangeColor::convertMario() {

    sf::Color color;

    for( int i = 0;  i < texture.getSize().y; ++i ){
        for( int j = 0; j < texture.getSize().x; ++j ){
            color = sf::Color( 0, image.getPixel(j, i).g, 0);
            image.setPixel(j, i, color);
        }
    }

    texture.loadFromImage(image);
    tempSprite.setTexture(texture);
}

sf::Color getColor(sf::Color color){

    if( color.r < color.g && color.r < color.b )
        return sf::Color(0, color.g, color.b);

    if( color.g < color.r && color.g < color.b )
        return sf::Color(color.r, 0, color.b);

    if( color.b < color.r && color.b < color.g )
        return sf::Color(color.r, color.g, 0);


    return sf::Color(0, color.g, color.b);
}

sf::Color BlackWhite(sf::Color color){

    int avg = (color.r + color.g + color.b)/3;

    return sf::Color(avg, avg, avg);

}



void ChangeColor::convertBlackWhite() {
    sf::Color color;

    for( int i = 0;  i < texture.getSize().y; ++i ){
        for( int j = 0; j < texture.getSize().x; ++j ){
            color = image.getPixel(j, i);
            color = BlackWhite(color);
            image.setPixel(j, i, color);
        }
    }

    texture.loadFromImage(image);
    tempSprite.setTexture(texture);
}

void ChangeColor::convertBubbleGum() {

    sf::Color color;

    for( int i = 0;  i < texture.getSize().y; ++i ){
        for( int j = 0; j < texture.getSize().x; ++j ){
      //      color = sf::Color( 0, image.getPixel(j, i).g, 0);
            color = image.getPixel(j,i);
        //    image.setPixel(j, i, lowBits(color));
        }
    }

    texture.loadFromImage(image);
    tempSprite.setTexture(texture);
}