#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(640,400), "Example 7", Style::None);
    window.setFramerateLimit(60);

    CircleShape hoop, ball;
    int dir = 0;
    hoop.setRadius(50.f);
    hoop.setFillColor(Color::Black);
    hoop.setOutlineThickness(2);
    hoop.setOutlineColor(Color::Blue);
    hoop.setPosition(Vector2f(0, 10.f));

    ball.setRadius(20.f);
    bool isShot = false;
    ball.setFillColor(Color::Red);
    ball.setPosition(Vector2f(0, window.getSize().y - ball.getRadius() * 3));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        // Update hoop
        if (hoop.getPosition().x <= 0)
            dir = 1;
        else if (hoop.getPosition().x + hoop.getRadius()*2 >= window.getSize().x) 
            dir = 0;
        
        if (dir == 0)
            hoop.move(-5.f, 0);
        else
            hoop.move(5.f, 0);

        // Update ball
        if (Mouse::isButtonPressed(Mouse::Left) && !isShot)
            isShot = true;
        
        if (!isShot)
            ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
        else
            ball.move(0, -5.f);

        // Collision ball
        if (ball.getPosition().y <= 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
        {
            // Reset ball
            isShot = false;
            ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
        }

        // Draw
        window.clear(Color::White);

        //Draw everything
        window.draw(hoop);
        window.draw(ball);

        window.display();
    }
    
    return 0;
}

