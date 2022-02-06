output: main.o Game.o TextureManager.o GameObject.o 
	 g++ -std=c++0x -Wall main.o Game.o TextureManager.o GameObject.o -lSDL2 -lSDL2_image -o output

main.o: main.cpp
	 g++ -c main.cpp

Game.o: Game.cpp Game.h
	 g++ -c Game.cpp

TextureManager.o: TextureManager.cpp TextureManager.h
	 g++ -c TextureManager.cpp 

GameObject.o: GameObject.cpp GameObject.h
	 g++ -c GameObject.cpp


