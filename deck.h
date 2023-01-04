#ifndef DECK_H
#define DECK_H

#include "card.h"

#define DECK_SIZE 52

// This comment is because I am getting lost in the sauce

// I don't know how I want the positioning between cards and decks to work
// I think that decks and cards should both be able to position,
// but that decks should do initial positioning, and cards should then do all positioning afterward
// With open face hands (hands the player can see) the cards should snap back to the hand

// I think the draw function should check the event handler possibly
// The other option is the card checking event handler, but that gets messy fast (lots of calls)


class deck
{
    std::vector<card> cardSet;
    sf::RenderWindow *renderTarget;
    card *selectedCard;
public:
    int x;
    int y;
    deck(sf::RenderWindow *renderTarget);
    deck(sf::RenderWindow *renderTarget, int width, int height);
    virtual ~deck();
    bool shuffle();
    virtual bool cheatShuffle() { return false;};
    virtual void draw(); // this implementation is for a face down draw deck
    virtual void setPosition();
    card drawTop();
    card drawBottom();
    card copyTop();
    card copyBottom();
    bool placeBottom(card aCard);
    bool placeTop(card aCard);
    virtual void playCard(card *aCard = nullptr);

};

#endif // DECK_H
