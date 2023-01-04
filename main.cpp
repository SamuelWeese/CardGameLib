#include <iostream>
#include "deck.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

#define windowSizeLength 1000

#define windowSizeHeight 1000

int main(void)
{
        sf::Image BAD_TEXTURE;
        BAD_TEXTURE.create(10,10, sf::Color::Cyan);
        static sf::Texture aTexture;
        if (!aTexture.loadFromFile("/tmp/testing2.png"))
        {
            aTexture.loadFromImage(BAD_TEXTURE);
        }
        sf::Image BAD_TEXTURE2;
        BAD_TEXTURE2.create(10,10, sf::Color::Red);
        static sf::Texture aTexture2;
        if (!aTexture2.loadFromFile("/tmp/testing2.png"))
        {
            aTexture2.loadFromImage(BAD_TEXTURE2);
        }
        sf::RenderWindow window(sf::VideoMode(windowSizeLength, windowSizeHeight), "Card Lib Testing");


        deck aDeck(&window, 10,10);
        card aCard(&window, &aTexture, &aTexture, "Gabagool");
        card aCard3(&window, &aTexture2, &aTexture2, "Gabagool");
        aDeck.placeBottom(aCard);
        aDeck.placeBottom(aCard3);
        while (window.isOpen())
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        std::cout << "the right button was pressed" << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        aDeck.shuffle();
                    }
                    break;
                default:
                    ;
                }

                if (event.type == sf::Event::Closed)
                    window.close();

            }
            aDeck.draw();
            window.display();
            window.clear();
        }
}
