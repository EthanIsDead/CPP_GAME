#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filePath, SDL_Renderer* ren)
{
	SDL_Surface* tempSurface = IMG_Load(filePath); 
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface); 
	SDL_FreeSurface(tempSurface); 

	return tex; 
}

