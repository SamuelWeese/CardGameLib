#include "deck.h"

// Shuffle
#include <algorithm>
#include <random>

#define VECTOR_FRONT 0
#define VECTOR_LAST this->cardSet.size()-1
#define VECTOR_SIZE this->cardSet.size()

deck::deck(sf::RenderWindow *renderTarget)
{
    this->renderTarget = renderTarget;
}

deck::deck(sf::RenderWindow *renderTarget, int width, int height)
{
    this->renderTarget = renderTarget;
}

deck::~deck()
{

}
#include <iostream>

bool deck::shuffle() // needs to be reimplemented
{
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(this->cardSet), std::end(this->cardSet), rng);
    std::cout << "Shuffling!" << std::endl;
    return true;
}

card deck::drawTop()
{
    card retCard = card(this->renderTarget);
    if (VECTOR_SIZE > 0)
    {
        retCard = cardSet[VECTOR_FRONT];
        cardSet.erase(cardSet.begin());
    }
    return retCard;
}
card deck::drawBottom()
{
    card retCard = card(this->renderTarget);
    if (VECTOR_SIZE > 0)
    {
        retCard = cardSet[VECTOR_LAST];
        cardSet.pop_back();
    }
    return retCard;
}
card deck::copyTop()
{
    card retCard = card(this->renderTarget);
    if (cardSet.size() > 0)
    {
        retCard = cardSet[VECTOR_FRONT];
    }
    return retCard;
}

card deck::copyBottom()
{
    card retCard = card(this->renderTarget);
    if (VECTOR_SIZE > 0)
    {
        retCard = cardSet[VECTOR_LAST];
    }
    return retCard;
}

bool deck::placeBottom(card aCard)
{
    cardSet.insert(cardSet.begin(), aCard);
    return true;
}

bool deck::placeTop(card aCard)
{
    cardSet.emplace_back(aCard);
    return true;
}

void deck::draw()
{
   this->cardSet[VECTOR_FRONT].draw();
}

void deck::setPosition()
{
    for (card i : this->cardSet)
    {
        if (this->selectedCard == &i)
        {
            continue;
        }
        i.setPosition(this->x, this->y);
    }
}

void deck::playCard(card *aCard)
{
    card *tempPtr = aCard;

    if (aCard == nullptr) // selectedCard pointer is not static, so no easy default
    {
        tempPtr = this->selectedCard;
    }

}
