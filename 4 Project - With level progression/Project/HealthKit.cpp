#include "HealthKit.h"
#include <iostream>


HealthKit::HealthKit(int x, int y)
	: PlacableActor(x, y)
{

}

void HealthKit::Draw()
{
	std::cout << "K";
};