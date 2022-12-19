#include <iostream>
#include "card.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

#define windowSizeLength 720

#define windowSizeHeight 720

int main(void)
{
        sf::RenderWindow window(sf::VideoMode(windowSizeLength, windowSizeHeight), "Hannoi Tower");

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
                    }
                    break;
                }

                if (event.type == sf::Event::Closed)
                    window.close();

            }
            window.display();
            window.clear();
        }
}
