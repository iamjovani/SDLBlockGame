#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class Window {
public:
	Window(const std::string &title, int WIDTH, int HEIGHT);
	~Window();

	void pollEvent(SDL_Event &event);
	void clear() const;
	inline bool isClosed() const { return closed; }

private:
	bool init();

private:
	std::string title;
	int WIDTH = 800;
	int HEIGHT = 600;
	bool closed = false;

	SDL_Window *window = nullptr;

public:
 	static SDL_Renderer *renderer;
};
