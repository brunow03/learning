#include "Game.hpp"
#include "Player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

Game::Game(RenderWindow *window) 
{
	this->window = window;
	this->window->setFramerateLimit(60);

	// Init textures
	this->playerTexture.loadFromFile("./Textures/ship.png");
	this->bulletTexture.loadFromFile("./Textures/missileTex01.png");

	// Init player
	this->players.push_back(Player(&playerTexture, &bulletTexture));
	this->players.push_back(Player(&playerTexture, &bulletTexture, 
		Keyboard::I, Keyboard::K, Keyboard::J, Keyboard::L, Keyboard::RShift));

}

Game::~Game() 
{


}

void Game::Update() 
{
	for (size_t i = 0; i < this->players.size(); i++) 
	{
		this->players[i].Update(*this->window->getSize());
	}
}

void Game::Draw() 
{
	this->window->clear();

	for (size_t i = 0; i < this->players.size(); i++) 
	{
		players[i].Draw(*this->window);
	}

	this->window->display();
}