#include <iostream>

#include <SDL2/SDL.h>

#include "player.h"

int main()
{
	/////////////////////////////////////////////
	
	Player player("Dan"); 
	std::cout << player.getName() << std::endl; 
	
	player.setName("Gabe");

	std::cout << player.getName() << std::endl;

	//////////////////////////////////////////////////////

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);

    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }

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

