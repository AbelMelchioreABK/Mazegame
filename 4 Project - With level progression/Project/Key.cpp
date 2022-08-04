#include <iostream>
#include <windows.h>

#include "Key.h"
#include "AudioManager.h"
#include "GameplayState.h"

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "+";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}

void Key::Collide(GameplayState* state, int newX, int newY)
{
	if (!state->GetPlayer()->HasKey())
	{
		state->GetPlayer()->PickupKey(this);
		this->Remove();
		state->GetPlayer()->SetPosition(newX, newY);
		AudioManager::GetInstance()->PlayKeyPickupSound();
	}
}