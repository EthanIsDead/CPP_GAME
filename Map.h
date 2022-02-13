#pragma once

#include "Game.h"
#include "Tile.h"

class Map
{
public:
	Map(Tile* _tiles[], int numOfTiles, int _map[20][25], int w, int h); 
	~Map(); 

	void LoadMap(int arr[20][25]); 
	void DrawMap();  

private:
	SDL_Rect src, dest;

	int map[20][25]; 
	int numOfTiles;
	Tile* tiles[]; 
}; 

