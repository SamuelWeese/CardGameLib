#include "card.h"
#include <SFML/Graphics/Sprite.hpp>

card::card(sf::RenderWindow *displayWindow)
{
    this->displayWindow = displayWindow;
}
card::card(sf::RenderWindow *displayWindow, sf::Texture, std::string name)
{
    this->displayWindow = displayWindow;
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
