#include "Bullet.h"

//:_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)

Bullet::Bullet(const int &x,const int &y)
	: _y(y + 7), temp(x), _x(&temp)
{


}



int Bullet::getX()
{
	return *_x;
}


void Bullet::draw() const
{
	SDL_Rect rect = { *_x, _y, 3, 3 };

	SDL_SetRenderDrawColor(Window::renderer, r, g, b, a);
	SDL_RenderFillRect(Window::renderer, &rect);

}


void Bullet::move(int &playerXPOS)
{

	if (*_x != ((*_x) * 2) || *_x >= playerXPOS)
	{
		*_x += 1;
		Bullet::move(playerXPOS);
	}
	else
	{

	}


}



void Bullet::move()
{

	if (*_x != ((*_x) * 2) && *_x >= 0)
	{
		*_x += 1;
		
	}
	else 
	{

	}

}

Bullet::~Bullet()
{

}