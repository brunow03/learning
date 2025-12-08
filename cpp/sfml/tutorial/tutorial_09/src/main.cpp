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

    if (!catTex.loadFromFile("somefile"))
        throw "Could not load cat.png";

    cat.setTexture(catTex);
    cat.setScale(Vector2f(0.2f, 0.2f));
    int catSpawnTimer = 15;

    std::vector<Sprite> cats;
    cats.push_back(Sprite(cat));

    // Doge
    Texture dogeText;
    Sprite doge;

    if (!dogeText.loadFromFile("some toehr"))
        throw "Could not doge";

    doge.setTexture(dogeText);
    doge.setScale(Vector2f(1.f, 1.f));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        // Update
        //Doge (player)

        // Cats
        for (size_t i = 0; i < cats.size(); i++)
        {
            cats[i].move(-10.g, 0.f);
        }
        
        if (catSpawnTimer < 15)
            catSpawnTimer++;
        
        if (catSpawnTimer >= 15) 
        {
            cat.setPosition(window.getSize().x, rand() % window.getSize().y - cat.getGlobalBounds().height);
            cats.push_back(Sprite(cat));
            catSpawnTimer = 0;
        }

        // Draw
        window.clear();

        window.draw(doge);

        for (size_t i = 0; i < cats.size(); i++)
        {
            window.draw(cats[i]);
        }
        
        //Draw everything
        window.display();
    }
    
    return 0;
}

