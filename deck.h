#ifndef DECK_H
#define DECK_H

#include "card.h"

#define DECK_SIZE 52


class deck
{
    std::vector<card> cardSet;
    sf::RenderWindow *renderTarget;
public:
    deck(sf::RenderWindow *renderTarget);
    virtual ~deck();
    bool shuffle();
    virtual bool cheatShuffle() {};
    void draw();
    card drawTop();
    card drawBottom();
    card copyTop();
    card copyBottom();
    bool placeBottom(card aCard);
    bool placeTop(card aCard);


};

#endif // DECK_H
