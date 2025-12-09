#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(640,400), "Example 1", Style::None);
    window.setFramerateLimit(60);

    Font font;
    if (!font.loadFromFile("/home/bruno/xkcd-font-master/xkcd-script/font/xkcd-script.ttf"))
        throw("COULD NOT FONT!!");

    Text text;
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(Color::Red);
    text.setStyle(Text::Bold);
    text.setString("I\'m a font!\n \t:D");
    text.setPosition(0, window.getSize().y/2 - text.getGlobalBounds().height/2);
    // window.getSize().x/2 - text.getGlobalBounds().width/2
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        // Update
        text.move(5.f, 0.f);

        if (text.getPosition().x > window.getSize().x)
            text.setPosition(0.f, text.getPosition().y);

        // Draw
        window.clear();

        window.draw(text);

        //Draw everything
        window.display();
    }
    
    return 0;
}

