#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <math.h>
#include <vector>
#include <cstdlib>

using namespace sf;

class Bullet
{
public:
    CircleShape shape;
    Vector2f currVelocity;
    float maxSpeed;

    Bullet(float radius = 5.f)
        : currVelocity(0.f,0.f), maxSpeed(15.f)
    {
        this->shape.setRadius(radius);
        this->shape.setFillColor(Color::Red);
    }
};

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    RenderWindow window(VideoMode(800,600), "Example 1", Style::None);
    window.setFramerateLimit(60);

    // Player
    CircleShape player(25.f);
    player.setFillColor(Color::White);

    // Bullets
    Bullet b1;
    std::vector<Bullet> bullets;
    // bullets.push_back(Bullet(b1));

    // Enemy
    RectangleShape enemy;
    enemy.setFillColor(Color::Magenta);
    enemy.setSize(Vector2f(50.f, 50.f));
    int spawnCounter = 20;

    std::vector<RectangleShape> enemies;

    // Vectors
    Vector2f playerCenter;
    Vector2f mousePosWindow;
    Vector2f aimDir;
    Vector2f aimDirNorm;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        // Update
        playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
        mousePosWindow = Vector2f(Mouse::getPosition(window));
        aimDir = mousePosWindow - playerCenter;
        aimDirNorm = Vector2f(aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)), aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
        // aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

        std::cout << aimDirNorm.x << "\t" << aimDirNorm.y << "\n";

        // Player
        if (Keyboard::isKeyPressed(Keyboard::A))
            player.move(-10.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::D))
            player.move(10.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::W))
            player.move(0.f, -10.f);
        if (Keyboard::isKeyPressed(Keyboard::S))
            player.move(0.f, 10.f);

        // Enemies
        if (spawnCounter < 20)
            spawnCounter++;

        if (spawnCounter >= 20 && enemies.size() < 50)
        {
            enemy.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().x));
            enemies.push_back(RectangleShape(enemy));

            spawnCounter = 0;
        }
        
        // Shooting
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            b1.shape.setPosition(playerCenter);
            b1.currVelocity = aimDirNorm * b1.maxSpeed;

            bullets.push_back(Bullet(b1));
        }
        
        for (size_t i = 0; i < bullets.size(); i++)
        {
            bullets[i].shape.move(bullets[i].currVelocity);
            
            // Out of bounds
            if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > window.getSize().x
                || bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window.getSize().y)
            {
                bullets.erase(bullets.begin() + i);
            }
            else
            {
                // Enemy collision
                for (size_t k = 0; k < enemies.size(); k++)
                {
                    if (bullets[i].shape.getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
                    {
                        bullets.erase(bullets.begin() + i);
                        enemies.erase(enemies.begin() + k);
                        break;
                    }
                    
                }
            }

            if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > window.getSize().x
                || bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window.getSize().y)
            {
                bullets.erase(bullets.begin() + i);
            }
        }
        
        // Draw
        window.clear();

        for (size_t i = 0; i < enemies.size(); i++)
            window.draw(enemies[i]);
        
        window.draw(player);

        for (size_t i = 0; i < bullets.size(); i++)
            window.draw(bullets[i].shape);

        //Draw everything
        window.display();
    }
    
    return 0;
}

