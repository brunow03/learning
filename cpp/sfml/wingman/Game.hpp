#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Player.hpp"
#include <vector>

using namespace sf;

class Game {
private:
	RenderWindow *window;

	std::vector<Player> players;

	Texture playerTexture;
	Texture bulletTexture;
	
public:
	Game(RenderWindow *window);
	virtual ~Game();
	
	// Accessors
	inline RenderWindow& getWindow() { return *this->window;}

	// Setters

	// Functions
	void Update();
	void Draw();

};