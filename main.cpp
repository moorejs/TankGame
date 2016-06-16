#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Game.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(Window::WIDTH, Window::HEIGHT), "Game Window");

    Game game(window);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        game.update();
        game.draw();

        window.display();
    }

    return EXIT_SUCCESS;
}
