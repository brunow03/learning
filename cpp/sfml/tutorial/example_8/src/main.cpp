#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include <vector>

using namespace sf;
// using namespace std;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(640,400), "Example 1", Style::None);
    window.setFramerateLimit(60);

    // Balls
    CircleShape player;
    std::vector<CircleShape> projectiles;
    
    std::vector<RectangleShape> enemies;


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.KeyPressed && event.key.code == Keyboard::Escape)
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

