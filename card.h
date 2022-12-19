#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include <string>

enum player {};

class card
{
    sf::RenderWindow *displayWindow;
    player *owner;
public:
    sf::Sprite cardBack;
    sf::Sprite cardFront;
    bool faceUp;
    char fenChar;
    card(sf::RenderWindow *);
    card(sf::RenderWindow *, sf::Texture, std::string name);
    void draw();
    void flip();

};

#endif // CARD_H
