#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourceManager.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    ResourceManager resources;

    /* sprite from SFML demo */
    sf::Sprite sprite(resources.getTexture("cute_image.jpg"));

    sf::Sprite blue(resources.getTexture("tileset.png"), {0, 0, 32, 32});
    blue.setPosition(400.f, 400.f);

    sf::Sprite red(resources.getTexture("tileset.png"), {32, 0, 32, 32});
    red.setPosition(500.f, 500.f);

    // Create a graphical text to display
    /*sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
        sf::Text text("Hello SFML", font, 50);*/
    // Load a music to play
    sf::Music music;
    /*if (!music.openFromFile("nice_music.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();*/
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
        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);
        window.draw(red);
        window.draw(blue);

        // Draw the string
        //window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
