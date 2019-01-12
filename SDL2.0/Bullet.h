#pragma once
#include "Entity.h"
#include "Player.h"



class Bullet
{
public:
	Bullet(const int &x, const int &y);
	void draw() const;
	int getX();
	//void setX(int x);
	void move(int &playerXPOS);
	void move();
	~Bullet();

private:
	int *_x = &temp;
	int temp;
	const int _y;

	int r = 255, g = 255, b = 0, a = 0;

};