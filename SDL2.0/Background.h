#pragma once
#include <string>

class Player;

class Background 
{
public:
	Background(const std::string &IMG);
	Background();
	~Background();

	//static void scroll(Player &player, int Width);
	static void draw();
	static void update(const std::string &N_IMG);

private:
	static Background *instance;
	std::string _IMG;

};
