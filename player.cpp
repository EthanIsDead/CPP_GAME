#include "player.h"

//constructers
Player::Player(){}

Player::Player(std::string name){ this->name = name; }

Player::~Player(){}

//functions
std::string Player::getName(){ return name; } 

void Player::setName(std::string name){ this->name = name; }

