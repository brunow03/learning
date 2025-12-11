#include <iostream>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1366, 768), "View Tutorial", Style::Fullscreen);

	View mainView;
	mainView.setSize(1366, 768);
	// mainView.setViewport(FloatRect(0, 0, 1366, 768));

	RectangleShape player;
	player.setSize(Vector2f(50.f, 50.f));
	player.setPosition(500.f, 500.f);

	RectangleShape object;
	object.setSize(Vector2f(50.f, 50.f));
	object.setPosition(500.f, 500.f);

	RectangleShape UIElement;
	UIElement.setSize(Vector2f(300.f, 20.f));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
		}

		// Update
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			player.move(-0.5f, 0.f);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			player.move(0.5f, 0.f);
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player.move(0.f, -0.5f);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player.move(0.f, 0.5f);
		}

		mainView.setCenter(player.getPosition());

		// Draw
		window.clear();
		
		// Draw stuff
		window.setView(mainView);
		window.draw(player);
		window.draw(object);

		// Draw UI
		window.setView(window.getDefaultView());
		window.draw(UIElement);

		// Finished drawing
		window.display();
	}

	return 0;
}