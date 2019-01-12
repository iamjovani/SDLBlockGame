#include "Window.h"

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, int WIDTH, int HEIGHT) 
	: title(title), WIDTH(WIDTH), HEIGHT(HEIGHT)
{
	closed = !init();
}

Window::~Window() 
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

bool Window::init() 
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		std::cerr << "SDL [Failed] to INITIALIZE SDL!"<< std::endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		std::cerr << "Image [Failed] to INITIALIZE! " << std::endl;
		return false;
	}

	window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, 0);

	if (window == nullptr) 
	{
		std::cerr << "[Failed] to create WINDOW!" << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) 
	{
		std::cerr << "[Failed] to create RENDERER!" << std::endl;
		return false;
	}

	return true;
}

void Window::pollEvent(SDL_Event &event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.type)
		{

		case SDL_QUIT:
			closed = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				closed = true;
				break;
			}

		}
	}
}

void Window::clear() const 
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}