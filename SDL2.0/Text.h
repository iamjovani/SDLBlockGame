#pragma once

#include "Window.h"

class Text
{
public:
	Text(const std::string &fpath, int fsize, const std::string &message, SDL_Color &fcolor);
	void display(int x, int y, SDL_Renderer *renderer) const;

	static SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &fpath, int fsize, const std::string &message, SDL_Color &fcolor);

private:
	SDL_Texture *textTexture = nullptr;
	mutable SDL_Rect textRect;
};