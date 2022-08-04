#include <iostream>
#include "Money.h"
#include "AudioManager.h"
#include "GameplayState.h"

Money::Money(int x, int y, int worth)
	: PlacableActor(x, y)
	, m_worth(worth)
{

}

void Money::Draw()
{
	std::cout << "$";
}

void Money::Collide(GameplayState* state, int newX, int newY)
{
	AudioManager::GetInstance()->PlayMoneySound();
	this->Remove();
	state->GetPlayer()->AddMoney(this->GetWorth());
	state->GetPlayer()->SetPosition(newX, newY);
}