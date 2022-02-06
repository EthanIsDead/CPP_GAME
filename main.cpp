#include <iostream>

#include <SDL2/SDL.h>

#include "Game.h"

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING); 
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0); 

	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0); 
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

    SDL_UpdateWindowSurface(window);

	bool keep_window_open = true;
	while(keep_window_open)
	{
		SDL_Event e;
		while(SDL_PollEvent(&e) > 0)
		{
			switch(e.type)
			{
				case SDL_QUIT:
					keep_window_open = false;
					break;
			}

			SDL_UpdateWindowSurface(window);
		}
	}

	return 0;
}

