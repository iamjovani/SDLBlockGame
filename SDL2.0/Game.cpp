#include "Game.h"
#include "Bullet.h"

Game* Game::instance = 0;

Game::Game()
{
	int Width = WIDTH;
	int Height = HEIGHT;


	Window window("Block Busster", WIDTH, HEIGHT);
	SDL_Rect background = { 0, 0, WIDTH, HEIGHT };


	//Loading Image for the background
	std::string bimg = "res/background.bmp";
	SDL_Surface *Bsurface = IMG_Load(bimg.c_str());

	//Creating a texture from the image
	backgroundTexture = SDL_CreateTextureFromSurface(Window::renderer, Bsurface);
	SDL_QueryTexture(backgroundTexture, NULL, NULL, &Width, &Height);

	Entity Ground(1850, 90, { 0, 570 }, 0, 0, 0, 0);
	Entity rect3(50, 50, { 560, 190 }, 0, 0, 0, 0);

	//Text text("res/AdobeArabic-Regular.ttf", 30, "Message", {255, 255, 200});

	Player player(30, 30, { 10, 240 }, "res/Player12.png"); //WIDTH, HEIGHT, X, Y // 150 -> Y POS 
															/*Ideal ground height for player is 540*/

	Entity rect2(50, 50, { 250, 350 }, 0, 0, 0, 0);

	Enemy enemy(30, 30, { 500, 540 }, "res/testO.bmp");
	Entity Spikes(150, 50, { 300, 540 }, "res/Spikes.png");

	int b = 250;
	int c = 250;


	Bullet en(b, c);

	std::vector<Entity> Clist;

	Clist.emplace_back(rect3);
	Clist.emplace_back(enemy);
	Clist.emplace_back(rect2);
	Clist.emplace_back(Ground);


	const int FRAMES_PER_SECOND = 500;
	Timer fps;

	// Game Loop
	while (!window.isClosed())
	{
		fps.Start();

		if (background.x < 0)
		{
			background.x = 0;
		}


		if (background.y < 0)
		{
			background.y = 0;
		}


		if (background.x >= WIDTH)
			background.x = WIDTH + (WIDTH / 2);

		
		/*
		if (background.y  >= WIDTH)
		background.y = WIDTH - 440;
		*/
		background.x = player.position.x - (WIDTH / 2);
		//background.y = player.position.y - (HEIGHT / 2);

		SDL_RenderCopy(Window::renderer, backgroundTexture, &background, NULL);

		player.draw(background);
		std::cout << (int) player.position.y << std::endl;
		Ground.draw(background);
		rect2.draw(background);
		rect3.draw(background);

		enemy.draw(background);
		enemy.move(player);
		


		en.draw();
		en.move();


		handleEvent(window, player);
		Gravity(window, player, Clist);

		window.clear();

		
		if (fps.GetTimerTicks() < 1000 / FRAMES_PER_SECOND)
		{
			SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.GetTimerTicks());
		}
		
	}
}


void Game::Gravity(Window &window, Player &player, std::vector<Entity> &Clist)
{

	if (!player.checkCollision(Clist[0]) && !player.checkCollision(Clist[1]) && !player.checkCollision(Clist[2]) && !player.checkCollision(Clist[3]))
	{
		player.position.y += 1;
		Game::handleEvent(window, player);
	}


	else  if (player.checkCollision(Clist[0]) && player.checkCollision(Clist[1]) && player.checkCollision(Clist[2]) && player.checkCollision(Clist[3]))
	{

		std::cout << "collision!" << std::endl;
		Game::avoidCollision(player, Clist, window);
	}

}




void Game::avoidCollision(Player &rect1, std::vector<Entity> &list, Window &window)
{
	for (Entity a : list)
	{
		// Check edges
		if (rect1.position.x >= a.position.x)// Left 1 is right of right 2
		{
			rect1.position.x = rect1.position.x + 3;
			Game::handleEvent(window, rect1);
		}

		if (rect1.position.x <= a.position.x) // Right 1 is left of left 2
		{
			rect1.position.x = rect1.position.x - 3;
			Game::handleEvent(window, rect1);
		}

		if (rect1.position.y >= a.position.y) // Top 1 is below bottom 2
		{
			rect1.position.y = rect1.position.y + 3;
			Game::handleEvent(window, rect1);
		}

		if (rect1.position.y <= a.position.y) // Bottom 1 is above top 2 
		{
			rect1.position.y = a.position.y - 3;
			Game::handleEvent(window, rect1);
		}
	}
}



void Game::handleEvent(Window &window, Player &player)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		player.pollEvent(event);
		window.pollEvent(event);
	}

}

Game* Game::getInstance()
{
	if (instance == 0)
	{
		instance = new Game;
	}

	return instance;
}

Game::~Game()
{
	SDL_DestroyTexture(backgroundTexture);
	backgroundTexture = nullptr;
	instance = nullptr;
}
