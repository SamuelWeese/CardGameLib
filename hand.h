#ifndef HAND_H
#define HAND_H

#include "deck.h"

class hand : public deck
{
    player owner;
    deck *drawPile;
    deck *discardPile;
public:
    hand(sf::RenderWindow *renderTarget, int x, int y);
};

#endif // HAND_H
