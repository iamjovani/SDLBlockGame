#pragma once
#include "Window.h"
#include "Utility.h"

using namespace Util;


class Entity
{
public:
	Entity(int w, int h, Vector2 postion, int r, int g, int b, int a);
	Entity(int w, int h, Vector2 postion, const std::string &img);
	virtual ~Entity();

	bool checkCollision(const Entity &rect);
	void draw(SDL_Rect &Camera) const;
	void setTexture(SDL_Texture *texture);
	void draw() const;
	SDL_Texture *getTexture();

public:
	int _w, _h;
	int _r, _g,
		_b, _a;

	Vector2 position;
	std::string image;

	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = nullptr;
};