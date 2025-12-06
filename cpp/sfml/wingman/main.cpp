#include "Game.hpp"
#include "Player.hpp"

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

using namespace sf;

int main(int argc, char const *argv[])
{
	RenderWindow window(VideoMode(800, 600), "Wingman", Style::Default);
	
	Game game(&window);

	// Game loop
	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
				window.close();
			}
		}
		
		game.Update();
		game.Draw();
	}

	
	
	return 0;
}