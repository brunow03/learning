#include <iostream>
#include <sstream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main(int argc, char const *argv[])
{
    // Init game
    float gridSizeF = 100.f;
    unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
    float dt = 0.f;
    Clock dtClock;

    Vector2i mousePosScreen;
    Vector2i mousePosWindow;
    Vector2f mousePosView;
    Vector2u mousePosGrid;

    Font font;
    font.loadFromFile("Fonts/xkcd-script.ttf");
    Text text;
    text.setCharacterSize(12);
    text.setFillColor(Color::White);
    text.setFont(font);
    text.setPosition(20.f, 20.f);
    // text.setString("TEST");

    RenderWindow window(VideoMode(1366, 768), "SFML", Style::Fullscreen);
    window.setFramerateLimit(60);

    // Init window
    View view;
    view.setSize(1366.f, 768.f);
    view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
    float viewSpeed = 200.f;

    window.setView(view);

    // Init game elements
    RectangleShape shape(Vector2f(gridSizeF, gridSizeF));

    const int mapSize = 10;

    std::vector<std::vector <RectangleShape>> tileMap;

    tileMap.resize(mapSize, std::vector<RectangleShape>());

    for (int x = 0; x < mapSize; x++)
    {
        tileMap[x].resize(mapSize, RectangleShape());
        for (int y = 0; y < mapSize; y++)
        {
            tileMap[x][y].setSize(Vector2f(gridSizeF, gridSizeF));
            tileMap[x][y].setFillColor(Color::White);
            tileMap[x][y].setOutlineThickness(1.f);
            tileMap[x][y].setOutlineColor(Color::Black);
            tileMap[x][y].setPosition(x * gridSizeF, y * gridSizeF);
        }
    }

    int fromX = 0;
    int toX = 0;
    int fromY = 0;
    int toY = 0;

    RectangleShape tileSelector(Vector2f(gridSizeF, gridSizeF));
    tileSelector.setFillColor(Color::Transparent);
    tileSelector.setOutlineThickness(1.f);
    tileSelector.setOutlineColor(Color::Green);

    while (window.isOpen())
    {
        // Update dt
        dt = dtClock.restart().asSeconds();

        // Update mouse positions
        mousePosScreen = Mouse::getPosition();
        mousePosWindow = Mouse::getPosition(window);
        window.setView(view);
        mousePosView = window.mapPixelToCoords(mousePosWindow);

        if (mousePosView.x >= 0.f)
            mousePosGrid.x = mousePosView.x / gridSizeU;
        if (mousePosView.y >= 0.f)
            mousePosGrid.y = mousePosView.y / gridSizeU;
        window.setView(window.getDefaultView());

        // Update game elements
        tileSelector.setPosition(mousePosGrid.x * gridSizeF, mousePosGrid.y * gridSizeF);

        // Update UI
        std::stringstream ss;
        ss << "Screen: " << mousePosScreen.x << " " << mousePosScreen.y << "\n"
            << "Window: " << mousePosWindow.x << " " << mousePosWindow.y << "\n"
            << "View: " << mousePosView.x << " " << mousePosView.y << "\n"
            << "Grid: " << mousePosGrid.x << " " << mousePosGrid.y << "\n";
        
        text.setString(ss.str());

        // Events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
        }

        // Update

        // Update input
        if (Keyboard::isKeyPressed(Keyboard::A)) // Left
            view.move(-viewSpeed * dt, 0.f);
        else if (Keyboard::isKeyPressed(Keyboard::D)) // Right
            view.move(viewSpeed * dt, 0.f);

        if (Keyboard::isKeyPressed(Keyboard::W)) // Up
            view.move(0.f, -viewSpeed * dt);
        else if (Keyboard::isKeyPressed(Keyboard::S)) // Down
           view.move(0.f, viewSpeed * dt);

        // Render
        window.clear();

        // Render game element
        window.setView(view);

        window.draw(shape);

        fromX = mousePosGrid.x - 2;
        toX = mousePosGrid.x + 2;

        fromY = mousePosGrid.y - 2;
        toY = mousePosGrid.y + 2;

        // fromX
        if (fromX < 0)
            fromX = 0;
        else if (fromX >= mapSize)
            fromX = mapSize - 1;

        // toX
        if (toX < 0)
            toX = 0;
        else if (toX >= mapSize)
            toX = mapSize - 1;
        
        // fromY
        if (fromY < 0)
            fromY = 0;
        else if (fromY >= mapSize)
            fromY = mapSize - 1;

        // toY
        if (toY < 0)
            toY = 0;
        else if (toY >= mapSize)
            toY = mapSize - 1;

        // Draw tiles
        for (int x = fromX; x < toX; x++)
            for (int y = fromY; y < toY; y++)
                window.draw(tileMap[x][y]);

        window.draw(tileSelector);

        // Render ui
        window.setView(window.getDefaultView());

        window.draw(text);

        // Done drawing
        window.display();
    }

    return 0;
}

