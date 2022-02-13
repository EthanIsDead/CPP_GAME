#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game
{
public:
	static SDL_Renderer *renderer; 

	Game(); 
	~Game(); 

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); 
	
	void handleEvents(); 
	void update(); 
	void render(); 
	void clean(); 
    
	bool running(); 

private:
	bool isRunning; 
	SDL_Window *window; 
}; 


