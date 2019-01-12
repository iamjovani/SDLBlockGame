#pragma once
#include "Window.h"
#include "Entity.h"
#include "Text.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include "Timer.h"

#define WIDTH 1000 // WIDTH OF SCREEN
#define HEIGHT 600 // HEIGHT OF SCREEN

class Game
{

public:
	Game();
	~Game();
	static Game* getInstance();
	static void handleEvent(Window &window, Player &player);
	static void avoidCollision(Player &rect1, std::vector<Entity> &list, Window &window);
	static void Gravity(Window &window, Player &player, std::vector<Entity> &Clist);
	//static void Background();

private:
	static Game *instance;
	SDL_Texture *backgroundTexture = nullptr;
};