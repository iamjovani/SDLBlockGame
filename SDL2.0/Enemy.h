#pragma once
#include "Entity.h"

class Player;

class Enemy : public Entity
{
public:
	Enemy(int w, int h, Vector2 postion, int r, int g, int b, int a);
	Enemy(int w, int h, Vector2 postion, const std::string &img);
	void move(Player &player);
	~Enemy();


};