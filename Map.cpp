#include "Map.h"
#include "TextureManager.h"
#include "Tile.h"

Map::Map(std::vector<Tile*> _tiles, int* _map, int _mapRows, int _mapCols, int w, int h)
{
	for(int i = 0; i < _tiles.size(); i++)
	{
		tiles.push_back(_tiles[i]); 	
	}	

	mapRows = _mapRows; 
	mapCols = _mapCols; 

	LoadMap(_map); 

	tileWidth = w; 
	tileHeight = h; 

	src.x = src.y = 0; 
	src.w = dest.w = w; 
	src.h = dest.h = h; 

	dest.x = dest.y = 0; 
}

void Map::LoadMap(int* arr)
{
	map = new int[mapRows * mapCols]; 

	for(int i = 0; i < mapRows; i++)
	{
		for(int j = 0; j < mapCols; j++)
		{
			*(map + i * mapCols + j) = *(arr + i * mapCols + j); 
		}
	}
}

void Map::DrawMap()
{
	int type = -1;
   	
	for(int row = 0; row < mapRows; row++)
	{
		for(int col = 0; col < mapCols; col++)
		{
			type = *(map + row * mapCols + col); 
			dest.x = col * tileWidth; 
			dest.y = row * tileHeight; 	

			for(int i = 0; i < tiles.size(); i++)
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
