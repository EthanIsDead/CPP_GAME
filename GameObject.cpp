#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y, int w, int h)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

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
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect); 
}
