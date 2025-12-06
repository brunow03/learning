#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Bullet.hpp"


using namespace sf;

class Player {
private:
	unsigned playerNr;

	int shootTimer;
	int damageTimer;
	int shootTimerMax;
	int damageTimerMax;

	Texture *texture;
	Sprite sprite;
	RectangleShape hitBox;

	Texture *bulletTexture;
	std::vector<Bullet> bullets;

	int controls[5];

	int level;
	int exp;
	int expNext;

	int hp;
	int hpMax;

	int damage;
	int damageMax;

	int score;

public:

	Player(Texture *texture, Texture *bulletTexture, int UP = 22, int DOWN = 18, 
		int LEFT = 0, int RIGHT = 3, int SHOOT = 57);
	virtual ~Player();
	
	void Movement();
	void Draw(RenderTarget &target);
	void Update(Vector2u windowBounds);

	// Static
	static unsigned players;



};