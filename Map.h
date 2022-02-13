#pragma once

#include "Game.h"
#include "Tile.h"

class Map
{
public:
	Map(std::vector<Tile*> _tiles, int* _map, int _mapRows, int _mapCols, int w, int h); 
	~Map(); 

	void LoadMap(int* arr); 
	void DrawMap();  

private:
	SDL_Rect src, dest;

	int* map; 
	int numOfTiles;
	std::vector<Tile*> tiles;  

	int tileWidth; 
	int tileHeight;

	int mapRows; 
	int mapCols; 	
}; 
