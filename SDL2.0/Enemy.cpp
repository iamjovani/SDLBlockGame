#include "Enemy.h"
#include <random>
#include <ctime>
#include "Player.h"


Enemy::Enemy(int w, int h, Vector2 postion, int r, int g, int b, int a)
	:Entity(w, h, postion, r, g, b, a)
{

}


Enemy::Enemy(int w, int h, Vector2 postion, const std::string &img)
	: Entity(w, h, postion, img)
{
}


void Enemy::move(Player &player)
{

	std::mt19937 random(time(NULL));
	std::uniform_int_distribution<int> distro(30, 970);

	int val = distro(random);


	if (this->checkCollision(player)) 
	{
		std::string img1 = "res/test.bmp";
		surface = IMG_Load(img1.c_str());
		texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
		setTexture(texture);
		position.x += 0;
	}

	if (position.x != val)
		if (position.x > val) 
		{
			std::string img = "res/testO.bmp";
			surface = IMG_Load(img.c_str());
			texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
			setTexture(texture);

			position.x -= 0.7;

		}


		 if (position.x < val) 
		{
			std::string img = "res/testO(Right).bmp";
			surface = IMG_Load(img.c_str());
			texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
			setTexture(texture);

			position.x += 0.7;

		}


	//TODO: Use the open mouth image when enemy is close to or about to pass through player.
}


Enemy::~Enemy()
{

}