#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class SwagBall 
{
private:
	sf::CircleShape shape;
	int type;

	void initShape(const sf::RenderWindow& window);
public:

	SwagBall(const sf::RenderWindow& window, int type);
	virtual ~SwagBall();
	
	// Accessors
	const sf::CircleShape getShape() const;

	// Functions
	void update();
	void render(sf::RenderTarget& target);
};