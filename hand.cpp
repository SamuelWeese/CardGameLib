#include "hand.h"


void hand::draw()
{
    if (curved)
    {
        for (auto aCard : this->cardSet)
        {
            aCard.draw();
        }
    }
}

void hand::setPosition()
{
    int middle = (float)cardSet.size() / 2.0f + 0.5f; // 0.5f rounding is suspect TODO LIGHT
    for (int i  = 0; i < cardSet.size(); i++)
    {
        float totalRotation = (middle - i)*(-1)*(this->curved);
        while (totalRotation > 360)
        {
            totalRotation -= 360;
        }
        while (totalRotation < 0)
        {
            totalRotation += 360;
        }
        cardSet[i].setRotation(totalRotation);
    }
}
