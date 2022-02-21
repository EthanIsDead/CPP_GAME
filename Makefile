output: main.o Game.o TextureManager.o GameObject.o Map.o Tile.o Vector2D.o
	 g++ -std=c++0x -Wall main.o Game.o TextureManager.o GameObject.o Map.o Tile.o Vector2D.o -lSDL2 -lSDL2_image -o output

main.o: main.cpp
	 g++ -c main.cpp

Game.o: Game.cpp Game.h
	 g++ -c Game.cpp

TextureManager.o: TextureManager.cpp TextureManager.h
	 g++ -c TextureManager.cpp 

GameObject.o: GameObject.cpp GameObject.h
	 g++ -c GameObject.cpp

Map.o: Map.cpp Map.h
	 g++ -c Map.cpp

Tile.o: Tile.cpp Tile.h
	 g++ -c Tile.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	 g++ -c Vector2D.cpp

