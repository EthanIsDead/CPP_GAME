#pragma once

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	
	//TEMP VARIABLES
	Vector2D velocity;
	float speed; 	
	//

	TransformComponent()
	{
		position.x = 0.0f; 
		position.y = 0.0f; 
	}
	
	TransformComponent(float x, float y)
	{
		position.x = x; 
		position.y = y; 		
	}

	void init() override
	{
		//TEMP VARIABLES
		speed = 5; 
		velocity.x = 0; 
		velocity.y = 0; 
		//
	}

	void update() override
	{
		//TEMP VARIABLES
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;		
		//
	}
}; 
