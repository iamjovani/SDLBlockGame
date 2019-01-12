#include "Player.h"

Player::Player(int w, int h, Vector2 position, int r, int g, int b, int a)
	: Entity(w, h, position, r, g, b, a),
	life(5), score(0), velocity(2.0f, 0.0f), gravity(0.0f, 1.0f)
{
}


Player::Player(int w, int h, Vector2 position, const std::string &img)
	: Entity(w, h, position, img),
	life(5), score(0), velocity(2.0f, 0.0f), gravity(0.0f, 1.0f)
{
}


void Player::pollEvent(SDL_Event &event)
{
	const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
	bool jumping = false;


	// Move right
	if (keyboard_state[SDL_SCANCODE_RIGHT])
		position.x += 8;
	// Move left
	if (keyboard_state[SDL_SCANCODE_LEFT])
		position.x -= 8;
	//Jump
	if (keyboard_state[SDL_SCANCODE_SPACE])
	{
		if (this->position.y == 541)
			this->position.y -= (10 - 1) *4.1;
			//this->position.y -= 140;
		else
			this->position.y -= 0;
	}
	
}

void Player::setVelocity(int x, int y)
{
	this->velocity.x = x;
	this->velocity.y = y;
}


void Player::setGravity(int x, int y)
{
	this->gravity.x = x;
	this->gravity.y = y;
}

void Player::gravityState()
{
	if (this->position.y < 540)
		this->position.y += 1;
}