output: main.o Game.o
	 g++ -std=c++0x -Wall main.o Game.o -lSDL2 -lSDL2_image -o output

main.o: main.cpp
	 g++ -c main.cpp

Game.o: Game.cpp Game.h
	 g++ -c Game.cpp


