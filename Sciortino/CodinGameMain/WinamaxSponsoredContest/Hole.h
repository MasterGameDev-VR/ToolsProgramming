#pragma once
#include "MapObject.h"
class Hole : public MapObject
{
public:
	Hole(int, int);
	~Hole();

	bool IsFilled();
	void IncreaseWeight();
	int GetWeight();
	void Fill();

private:
	int weight = 0;
	bool filled = false;

	
};

