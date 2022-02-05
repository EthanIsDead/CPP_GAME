output: main.o player.o
	g++ -std=c++0x -Wall main.o player.o -o output

main.o: main.cpp
	g++ -c main.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

