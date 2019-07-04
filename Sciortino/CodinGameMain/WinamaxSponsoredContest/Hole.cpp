#include "stdafx.h"
#include "Hole.h"


Hole::Hole(int x_init,int y_init) : MapObject(x_init, y_init, false)
{
}


Hole::~Hole()
{
}

bool Hole::IsFilled()
{
	return filled;
}

void Hole::IncreaseWeight() {
	weight += 1;
}

int& Hole::GetWeight() {
	return weight;
}

void Hole::Fill()
{
	filled =true;
}

void Hole::Empty()
{
	filled = false;
}
