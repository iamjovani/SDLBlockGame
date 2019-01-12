#pragma once
#include "Entity.h"
#include "Bullet.h"


class Player : public Entity
{
public:
	Player(int w, int h, Vector2 postion, int r, int g, int b, int a);
	Player(int w, int h, Vector2 postion, const std::string &img);
	void pollEvent(SDL_Event &event);
	void setVelocity(int x, int y);
	void setGravity(int x, int y);
	void gravityState();


private:
	SDL_Texture *PlayerTexture;
	int life;
	int score;
	int m_maxJumpY;
	Vector2 velocity;
	Vector2 gravity;
};