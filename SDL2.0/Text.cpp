#include "Text.h"

Text::Text(const std::string &fpath, int fsize, const std::string &message, SDL_Color &fcolor)
{
	textTexture = loadFont(Window::renderer,fpath, fsize, message, fcolor);
	SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
}

void Text::display(int x, int y, SDL_Renderer *renderer) const
{
	textRect.x = x;
	textRect.y = y;
	SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer, const std::string &fpath, int fsize, const std::string &message, SDL_Color &fcolor)
{
	TTF_Font *font = TTF_OpenFont(fpath.c_str(), fsize);

	if (!font) 
	{
		std::cerr << "Unable to load [FONT]!" << std::endl;
	}

	auto textSurface = TTF_RenderText_Solid(font, message.c_str(), fcolor);

	if (!textSurface) 
	{
		std::cerr << "Fail to create text surface!" << std::endl;
	}

	auto textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	if (!textTexture) 
	{
		std::cerr << "Fail to create text texture!" << std::endl;
	}

	SDL_FreeSurface(textSurface);

	return textTexture;
}
