#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Tile.h"

Map* map;
GameObject* player;

SDL_Renderer* Game::renderer = nullptr; 

Game::Game(){}

Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if(fullscreen)
		flags = SDL_WINDOW_FULLSCREEN; 	

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized" << std::endl; 

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags); 
		
		if(window)
			std::cout << "Window Created" << std::endl; 

		renderer = SDL_CreateRenderer(window, -1, 0); 

		if(renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
			std::cout << "Renderer Created" << std::endl;
		}

		isRunning = true; 
	}
	else
		isRunning = false;

	player = new GameObject("assets/player.png", 0, 0, 150, 150);

	SDL_Texture* dirt = TextureManager::LoadTexture("assets/dirt.png"); 
	SDL_Texture* grass = TextureManager::LoadTexture("assets/grass.png"); 
	SDL_Texture* water = TextureManager::LoadTexture("assets/water.png");

	int tilemap[20][25] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	Tile* tmpTiles[] = { new Tile(2, dirt), new Tile(1, grass), new Tile(0, water) }; 
	map = new Map(tmpTiles, 3, tilemap, 125, 125);
}

void Game::handleEvents()
{
	SDL_Event event; 
	SDL_PollEvent(&event); 

	switch(event.type)
	{
		case SDL_QUIT:
			isRunning = false; 
			break; 
		default:
			break; 
	}
}	

void Game::update()
{
	player->Update(); 
	player->xpos++; 
	player->ypos++; 	
}	

void Game::render()
{
	SDL_RenderClear(renderer); 
	
	//add stuff to render here
	map->DrawMap(); 
	player->Render(); 

	SDL_RenderPresent(renderer); 	
}

void Game::clean()
{
	SDL_DestroyWindow(window); 
	SDL_DestroyRenderer(renderer); 
	SDL_Quit(); 

	std::cout << "Game Cleaned" << std::endl; 
}

bool Game::running(){ return isRunning; }


