#include "Entity.h"

Entity::Entity(int w, int h, Vector2 position, int r, int g, int b, int a)
	:_w(w), _h(h), position(position), _r(r), _g(g), _b(b), _a(a)
{

}

Entity::Entity(int w, int h, Vector2 position, const std::string &img)
	: _w(w), _h(h), position(position), image(img)
{
	surface = IMG_Load(image.c_str());

	if (!surface)
	{
		std::cerr << "[Failed] to create surface!" << std::endl;
	}

	texture = SDL_CreateTextureFromSurface(Window::renderer, surface);

	if (!texture)
	{
		std::cerr << "[Failed] to create texture from surface!" << std::endl;
	}

	SDL_FreeSurface(surface);
}


void Entity::setTexture(SDL_Texture *texture) 
{
	this->texture = texture;
}

void Entity::draw() const
{
	SDL_Rect rect = { position.x , position.y, _w , _h };


	if (texture)
	{
		SDL_RenderCopy(Window::renderer, texture, nullptr, &rect);
	}
	else
	{

		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
}


void Entity::draw(SDL_Rect &Camera) const
{
	SDL_Rect rect = { position.x - Camera.x , position.y - Camera.y , _w , _h };

	/*
	SDL_Rect rect;

	rect.h = _h;
	rect.w = _w;
	rect.x = _x;
	rect.y = _y;
	*/

	if (texture)
	{
		SDL_RenderCopy(Window::renderer, texture, nullptr, &rect);
	}
	else
	{

		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
}





bool Entity::checkCollision(const Entity &rect2)
{
	return (position.x < rect2.position.x + rect2._w &&
		position.x + this->_w > rect2.position.x &&
		position.y < rect2.position.y + rect2._h &&
		this->_h + position.y > rect2.position.y);


}


SDL_Texture *Entity::getTexture()
{
	return texture;
}

Entity::~Entity()
{
	SDL_DestroyTexture(texture);
}