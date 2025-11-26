#include "Player.hpp"
#include "Bullet.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

unsigned Player::players = 0;

enum controls {UP = 0, DOWN, LEFT, RIGHT, SHOOT};

Player::Player(Texture *texture, Texture *bulletTexture,
		int UP, int DOWN, 
		int LEFT, int RIGHT, int SHOOT)
	:level(1), exp(0), expNext(100), 
	hp(10), hpMax(10), 
	damage(1), damageMax(2),
	score()
{
	this->texture = texture;
	this->bulletTexture = bulletTexture;
	this->sprite.setTexture(*this->texture);
	this->sprite.setScale(0.12f, 0.12f);

	this->shootTimerMax = 25;
	this->shootTimer = this->shootTimerMax;
	this->damageTimerMax = 10;
	this->damageTimer = this->damageTimerMax;


	this->controls[controls::UP] = UP;
	this->controls[controls::DOWN] = DOWN;
	this->controls[controls::LEFT] = LEFT;
	this->controls[controls::RIGHT] = RIGHT;
	this->controls[controls::SHOOT] = SHOOT;

	this->playerNr = Player::players;
	Player::players++;


}

Player::~Player() 
{
	
}

void Player::Movement() 
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::UP]))) 
		this->sprite.move(0.f, -10.f);

	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::DOWN]))) 
		this->sprite.move(0.f, 10.f);

	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::LEFT]))) 
		this->sprite.move(-10.f, 0.f);

	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::RIGHT]))) 
		this->sprite.move(10.f, 0.f);

	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::SHOOT]))) {
		this->bullets.push_back(Bullet(bulletTexture, this->sprite.getPosition()));
	}
	
}

void Player::Draw(RenderTarget &target) 
{
	target.draw(this->sprite);

	for (size_t i = 0; i < this->bullets.size(); i++) {
		this->bullets[i].Draw(target);
	}
}

void Player::Update(Vector2u windowBounds) 
{
	this->Movement();

	for (size_t i = 0; i < this->bullets.size(); i++) {
		this->bullets[i].Update();

		// Window bounds
		if (bullets[i].getPosition().x > windowBounds.x) 
		{
			bullets.erase(bullets.begin() + i);
			break;
		}
	}


}