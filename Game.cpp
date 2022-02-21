#include "Game.h"
#include "Map.h"
#include "Tile.h"

#include "ECS/Components.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr; 
SDL_Event Game::event; 

Manager manager; 
auto& player(manager.addEntity()); 

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

    //TEST ONE

	SDL_Texture* dirt = TextureManager::LoadTexture("assets/dirt.png"); 
	SDL_Texture* grass = TextureManager::LoadTexture("assets/grass.png"); 
	SDL_Texture* water = TextureManager::LoadTexture("assets/water.png");

	int tilemap[20][25] = {
		{0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,2,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,2,1,1,1,1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,2,2,1,1,1,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0},
		{2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,2,2,2,1,1,1,2,2,2,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,2,2,2,1,2,2,2,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,2,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	int tilemap_rows = 20; 
	int tilemap_cols = 25; 

	int* tilemap_dyn_arr = new int[tilemap_rows * tilemap_cols]; 

	for(int i = 0; i < tilemap_rows; i++)
	{
		for(int j = 0; j < tilemap_cols; j++)
		{
			*(tilemap_dyn_arr + i * tilemap_cols + j) = tilemap[i][j]; 
		}
	}

	std::vector<Tile*> tmpTiles{ new Tile(2, dirt), new Tile(1, grass), new Tile(0, water) }; 
	map = new Map(tmpTiles, tilemap_dyn_arr, tilemap_rows, tilemap_cols, 100, 100);


	//TEST TWO
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/player.png");
	player.addComponent<KeyboardController>(); 
}

void Game::handleEvents()
{
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
	manager.refresh(); 
	manager.update(); 	
}	

void Game::render()
{
	SDL_RenderClear(renderer); 

	//add stuff to render here
	map->DrawMap(); 
	manager.draw(); 

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
