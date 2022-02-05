#include <iostream>

#include "player.h"

int main()
{
	Player player("Dan"); 
	std::cout << player.getName() << std::endl; 
	
	player.setName("Gabe");

	std::cout << player.getName() << std::endl;
	
	return 0;
}

