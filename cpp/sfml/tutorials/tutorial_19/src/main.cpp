#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(800, 600), "Example 1", Style::Default);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
        }

        // Update

        // Draw
        window.clear();

        //Draw everything
        window.display();
    }
    
    return 0;
}

