#pragma once
#include "PlacableActor.h"
class Goal : public PlacableActor
{
public:
	Goal(int x, int y);

	virtual ActorType GetType() override { return ActorType::Goal; }
	virtual void Draw() override;
	void Collide(GameplayState* state, int newX, int newY);
};

