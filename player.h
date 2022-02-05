#include <string>

class Player
{
public:
	Player();
	Player(std::string name); 
	~Player();

	std::string getName(); 
	void setName(std::string name);
private:
	std::string name; 	
}; 


