#include "Tile.h"

Tile::Tile(int _id, SDL_Texture* _tex)
{
	id = _id; 
	texture = _tex; 
}

Tile::~Tile(){}

int Tile::getID(){ return id; }

SDL_Texture* Tile::getTexture(){ return texture; }


