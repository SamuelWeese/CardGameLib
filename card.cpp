#include "card.h"
#include <SFML/Graphics/Sprite.hpp>

card::card(sf::RenderWindow *displayWindow)
{
    this->displayWindow = displayWindow;
    this->faceUp = false;
}
card::card(sf::RenderWindow *displayWindow, sf::Texture *front, sf::Texture *back, std::string name, int width, int height)
{
    this->displayWindow = displayWindow;
    this->faceUp = false;

    this->cardFront.setTexture(front);
    this->cardBack.setTexture(back);

    this->setSize(width, height);
    this->setOutline();
    this->setPosition(100, 100);
}
void card::draw()
{
    if (faceUp)
    {
        displayWindow->draw(cardFront);
    }
    if (!faceUp)
    {
        displayWindow->draw(cardBack);
    }
}
void card::flip()
{
    this->faceUp = !faceUp;
}

void card::setPosition(int x, int y)
{
    this->cardBack.setPosition(sf::Vector2f(x, y));
    this->cardFront.setPosition(sf::Vector2f(x, y));
}
/* Redundant due to not using sprite
void card::setSize(int x, int y)
{
    int spriteHeight, spriteWidth;
    float spriteScaleHeight, spriteScaleWidth;
    if (this->cardFront.getTexture() != nullptr)
    {
        spriteWidth = cardFront.getGlobalBounds().width;
        spriteHeight = cardFront.getGlobalBounds().height;
        if (!spriteWidth) spriteWidth = 1;
        if (!spriteHeight) spriteHeight = 1;
        spriteScaleHeight = (float)x / (float)spriteHeight;
        spriteScaleWidth = (float)y / (float)spriteWidth;
        this->cardFront.scale(spriteScaleHeight, spriteScaleWidth);
    }
    if (this->cardBack.getTexture() != nullptr)
    {
        spriteWidth = cardBack.getGlobalBounds().width;
        spriteHeight = cardBack.getGlobalBounds().height;
        if (!spriteWidth) spriteWidth = 1;
        if (!spriteHeight) spriteHeight = 1;
        spriteScaleHeight = (float)x / (float)spriteHeight;
        spriteScaleWidth = (float)y / (float)spriteWidth;
        this->cardBack.scale(spriteScaleHeight, spriteScaleWidth);
    }
}*/


void card::setSize(int width, int height)
{
    this->cardFront.setSize(sf::Vector2f(width, height));
    this->cardBack.setSize(sf::Vector2f(width, height));
}

void card::setOutline(sf::Color outlineColor, float outlineWidth)
{
    this->cardBack.setOutlineColor(outlineColor);
    this->cardFront.setOutlineColor(outlineColor);
    this->cardBack.setOutlineThickness(outlineWidth);
    this->cardFront.setOutlineThickness(outlineWidth);
}
