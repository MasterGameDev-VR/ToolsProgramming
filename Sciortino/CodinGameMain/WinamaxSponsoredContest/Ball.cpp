#include "stdafx.h"
#include "Ball.h"


Ball::Ball(int x_init, int y_init, int power_init) :  MapObject(x_init, y_init, false), power(power_init)
{
}


Ball::~Ball()
{
}



int Ball::GetPower() {
	return power;
}
void Ball::LoadPaths(std::vector<Path>* paths_to_load) {
	paths = paths_to_load;
	//(*paths).assign((*paths_to_load).begin(), (*paths_to_load).end());
	//paths = paths_to_load;
}