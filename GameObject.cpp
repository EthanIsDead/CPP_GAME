#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y, int w, int h)
{
	renderer = ren; 
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	xpos = x; 
	ypos = y; 
	width = w; 
	height = h; 	
}

void GameObject::Update()
{
	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0; 
	srcRect.y = 0; 

	destRect.x = xpos; 
	destRect.y = ypos; 
	destRect.w = srcRect.w; 
	destRect.h = srcRect.h; 
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect); 
}
