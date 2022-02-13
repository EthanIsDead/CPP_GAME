#include "Map.h"
#include "TextureManager.h"
#include "Tile.h"

Map::Map(Tile* _tiles[], int _numOfTiles, int _map[20][25], int w, int h)
{
	numOfTiles = _numOfTiles;

	for(int i = 0; i < numOfTiles; i++)
	{
		tiles[i] = _tiles[i]; 
	}	

	LoadMap(_map); 

	src.x = src.y = 0; 
	src.w = dest.w = w; 
	src.h = dest.h = h; 

	dest.x = dest.y = 0; 
}

void Map::LoadMap(int arr[20][25])
{
	for(int row = 0; row < 20; row++)
	{
		for(int col = 0; col < 25; col++)
		{
			map[row][col] = arr[row][col];
		}
	}
}

void Map::DrawMap()
{
	int type = -1; 

	for(int row = 0; row < 20; row++)
	{
		for(int col = 0; col < 25; col++)
		{
			type = map[row][col];

			dest.x = col * 75; 
			dest.y = row * 75; 	

			for(int i = 0; i < numOfTiles; i++)
			{
				
				if(type == tiles[i]->getID())
				{
					TextureManager::Draw(tiles[i]->getTexture(), src, dest);
					break; 	
				}
				 
			}		
	 	
		}
	}
}
