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

deck::~deck()
{

}
bool deck::shuffle()
{

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(this->cardSet), std::end(this->cardSet), rng);
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
}
bool deck::placeTop(card aCard)
{
    cardSet.emplace_back(aCard);
}
void deck::draw()
{

}
