#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include <cstdlib>
#include <vector>

using namespace sf;

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    RenderWindow window(VideoMode(640,400), "Car do(d)ge");
    window.setFramerateLimit(60);

    // Cat
    Texture catTex;
    Sprite cat;

    if (!catTex.loadFromFile("./Textures/cat.png"))
        throw "Could not load cat.png";

    cat.setTexture(catTex);
    cat.setScale(Vector2f(0.2f, 0.2f));
    int catSpawnTimer = 15;

    std::vector<Sprite> cats;
        cats.push_back(Sprite(cat));

    // Doge
    Texture dogeText;
    Sprite doge;
    int hp = 10;
    RectangleShape hpBar;
    hpBar.setFillColor(Color::Red);
    hpBar.setSize(Vector2f((float)hp * 20.f, 20.f));
    hpBar.setPosition(200.f, 10.f);

    if (!dogeText.loadFromFile("./Textures/doge.png"))
        throw "Could not doge";

    doge.setTexture(dogeText);
    doge.setScale(Vector2f(1.f, 1.f));

    while (window.isOpen() && hp > 0)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        // Update
        //Doge (player)
        doge.setPosition(doge.getPosition().x, Mouse::getPosition(window).y);

        if (doge.getPosition().y > window.getSize().y - doge.getGlobalBounds().height)
            doge.setPosition(doge.getPosition().x, window.getSize().y - doge.getGlobalBounds().height);
        
        if (doge.getPosition().y < 0)
            doge.setPosition(doge.getPosition().x, 0);

        // Cats
        for (size_t i = 0; i < cats.size(); i++)
        {
            cats[i].move(-7.f, 0.f);

            if (cats[i].getPosition().x < 0 - cats[i].getGlobalBounds().width)
                cats.erase(cats.begin() + i);
        }
        
        if (catSpawnTimer < 40)
            catSpawnTimer++;
        
        if (catSpawnTimer >= 40) 
        {
            cat.setPosition(window.getSize().x, rand() % int(window.getSize().y - cat.getGlobalBounds().height));
            cats.push_back(Sprite(cat));
            catSpawnTimer = 0;
        }

        // Collision
        for (size_t i = 0; i < cats.size(); i++)
        {
            if (doge.getGlobalBounds().intersects(cats[i].getGlobalBounds()))
            {
                hp--;
                cats.erase(cats.begin() + i);
            }
        }

        // UI
        hpBar.setSize(Vector2f((float)hp * 20.f, 20.f));

        // Draw
        window.clear(Color::White);

        window.draw(doge);

        for (size_t i = 0; i < cats.size(); i++)
            window.draw(cats[i]);

        // UI
        window.draw(hpBar);
        
        //Draw everything
        window.display();
    }
    
    return 0;
}

