#include <iostream>

#include <SDL2/SDL.h>

#include "Game.h"

int main()
{
	Game *game = new Game(); 
	game->init("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, false); 

	while(game->running())
	{
		game->handleEvents(); 
		game->update(); 
		game->render(); 
	}

	game->clean(); 

	return 0;
}

