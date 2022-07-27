#pragma once
#include "PlacableActor.h"
class HealthKit : public PlacableActor
{
	public:
		HealthKit(int x, int y);

		virtual ActorType GetType() override { return ActorType::HealthKit; }
		virtual void Draw() override;
};

