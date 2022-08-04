#include <iostream>
#include <windows.h>
#include "Door.h"
#include "GameplayState.h"
#include "AudioManager.h"

Door::Door(int x, int y, ActorColor color, ActorColor closedColor)
	: PlacableActor(x, y, color)
	, m_isOpen(false)
	, m_closedColor(closedColor)
{

}

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_isOpen)
	{
		SetConsoleTextAttribute(console, (int)m_color);
	}
	else
	{
		SetConsoleTextAttribute(console, (int)m_closedColor);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}

void Door::Collide(GameplayState* state, int newX, int newY)
{
	if (!this->IsOpen())
	{
		if (state->GetPlayer()->HasKey(this->GetColor()))
		{
			this->Open();
			this->Remove();
			state->GetPlayer()->UseKey();
			state->GetPlayer()->SetPosition(newX, newY);
			AudioManager::GetInstance()->PlayDoorOpenSound();
		}
		else
		{
			AudioManager::GetInstance()->PlayDoorClosedSound();
		}
	}
	else
	{
		state->GetPlayer()->SetPosition(newX, newY);
	}
}

ActorType Door::GetType()
{
	return ActorType::Door;
};