#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <iostream>
#include <vector>
#include <array>

class Star
{
	std::mt19937& gen;  // Reference to external generator
	std::uniform_int_distribution<int> dist;

	float x, y, z;

	public:
		Star(std::mt19937& generator) 
		    : gen(generator), dist(0, 800) {  // Use member initializer list
		    x = dist(gen);  // Generate random values
		    y = dist(gen);
		    z = dist(gen);
		}

		void update() {

		}

		void show() {

		}

		int get_x () const {
			return x;
		}

		int get_y () const {
			return y;
		}

		// int get_z () {
		// 	return;
		// }
};

int main(int argc, char const *argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Starfield");
	window.setFramerateLimit(60);

	std::random_device rd;  // True random seed
	std::mt19937 gen(rd());

	std::vector<Star> stars;

	for(int i = 0; i < 800; i++) {
	    stars.emplace_back(gen);  // Constructs in-place
	}

	// Main loop
	while (window.isOpen()) {
	    sf::Event event;
	    while (window.pollEvent(event)) {
	        if (event.type == sf::Event::Closed || 
	            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
	            window.close();
	        }
	    }
	    
	    window.clear(sf::Color::Black);

	    for (auto& star : stars) {
			
	    }

		window.display();
	}

	return 0;
}