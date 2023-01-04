#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include <string>

enum player {};

class card
{
    sf::RenderWindow *displayWindow;
    player *owner;
    bool mouseDrag;
public:
    std::string id;
    sf::RectangleShape cardBack;
    sf::RectangleShape cardFront;
    bool faceUp;
    char fenChar;
    card(sf::RenderWindow *);
    card(sf::RenderWindow *, sf::Texture *front, sf::Texture *back,
    std::string name, int width = 50, int height = 100);
    void draw();
    void flip();
    void setSize(int x, int y);
    void setPosition(int x, int y);
    void setOutline(sf::Color = sf::Color::White, float outineWidth = 1);

};

#endif // CARD_H
