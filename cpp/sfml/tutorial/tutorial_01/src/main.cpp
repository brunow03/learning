#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(640,400), "Example 1", Style::None);
    window.setFramerateLimit(60);

    CircleShape shape(50.f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.key.code == Keyboard::Escape)
                window.close();
        }

        // Update
        shape.move(0.1f, 0.f);

        // Draw
        window.clear();

        //Draw everything
        window.draw(shape);
        window.display();
    }
    
    return 0;
}

