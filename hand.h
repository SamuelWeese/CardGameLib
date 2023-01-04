#ifndef HAND_H
#define HAND_H

#include "deck.h"

class hand : deck
{
    player *owner;
    std::vector<player *> viewers;
    deck *drawPile;
    deck *discardPile;
    float curved; // this number is an angle between individual cards, 180 would be flipping cards each card

public:
    // worry about constructor later, you bookmarked an article to read.
    // been too long since you did non explicit inheiritance/non composition
    // maybe this should be composition
    // maybe this will be easy peasy after sleeping
    hand(player *owner, int x = -1, int y = -1, int curved = 15);
    void draw() override;
    void setPosition() override;
};

#endif // HAND_H
