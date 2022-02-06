#pragma once

#include "Game.h"

class GameObject
{
public:
	int xpos; 
	int ypos;
	int width; 
	int height; 

	GameObject(const char* texturesheet, int x, int y, int w, int h); 
	~GameObject(); 

	void Update(); 
	void Render(); 

private:
	SDL_Texture* objTexture; 
	SDL_Rect srcRect, destRect; 
	SDL_Renderer* renderer; 
}; 
