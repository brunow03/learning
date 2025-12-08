#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(640,400), "Example 1", Style::None);
    window.setFramerateLimit(60);

    // Vector2f vec(10.f, 20.f);
    // vec.x;

    CircleShape circle(50.f);
    circle.setPosition(Vector2f(0.f, 0.f));

    RectangleShape rect(Vector2f(50.f, 100.f));
    rect.setPosition(Vector2f(400.f, 200.f));

    circle.setFillColor(Color(255,100,200,200));
    rect.setFillColor(Color(255,100,100,100));
        
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {   
            // Close on escape
            if (event.key.code == Keyboard::Escape)
                window.close();
        }

        // Update
        circle.move(0.5, 0.2f);
        circle.rotate(2.f);
        rect.move(-0.5f, -0.1f);
        rect.rotate(5.f);


        // Draw
        window.clear();

        //Draw everything
        window.draw(circle);
        window.draw(rect);

        window.display();
    }
    
    return 0;
}

