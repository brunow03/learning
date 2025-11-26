#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Cell {
	
}

void setup() {

}

void draw() {
	
}

int main(int argc, char const *argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Falling Sand");
	window.setFramerateLimit(60);

	// Main loop
	while (window.isOpen()) {
	    sf::Event event;
	    while (window.pollEvent(event)) {
	        if (event.type == sf::Event::Closed || 
	            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
	            window.close();
	        }
	    }

	    window.display();

    }

	return 0;
}
main