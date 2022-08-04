#include "HealthKit.h"
#include <iostream>
#include "AudioManager.h"
#include "GameplayState.h"

HealthKit::HealthKit(int x, int y)
	: PlacableActor(x, y)
{

}

void HealthKit::Draw()
{
	std::cout << "K";
};

void HealthKit::Collide(GameplayState* state, int newX, int newY)
{
	AudioManager::GetInstance()->PlayGainLiveSound();
	this->Remove();
	state->GetPlayer()->SetPosition(newX, newY);
	state->GetPlayer()->IncreaseLives();
}