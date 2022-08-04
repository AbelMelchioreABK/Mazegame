#include <iostream>
#include "Goal.h"
#include "AudioManager.h"
#include "GameplayState.h"

Goal::Goal(int x, int y)
	: PlacableActor(x, y)
{
	
}

void Goal::Draw()
{
	std::cout << "X";
}

void Goal::Collide(GameplayState* state, int newX, int newY)
{
	this->Remove();
	state->GetPlayer()->SetPosition(newX, newY);
	state->SetCompletion( true);
}