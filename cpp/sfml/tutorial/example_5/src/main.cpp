#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(640,400), "Example 1", Style::None);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();

            // if (event.type == Event::MouseButtonPressed && event.mou == Mouse::Left)
        }

        // if (Keyboard::isKeyPressed(Keyboard::Escape))
            // window.close():

        // if (Mouse::isButtonPressed(Mouse::Left))

        // Update

        // Draw
        window.clear();

        //Draw everything
        window.display();
    }
    
    return 0;
}
