#pragma once

#include "Game.h"

class Tile
{
public:
	Tile(int _id, SDL_Texture* _tex); 
	~Tile();

	int getID(); 
	SDL_Texture* getTexture(); 

private:
	int id; 
	SDL_Texture* texture; 
}; 
