#pragma once
#include <vector>
#include "Path.h"
#include "MapObject.h"
using namespace std;
class Ball : public MapObject
{
public:
	Ball(int, int, int);
	~Ball();

	int GetPower();
	void LoadPaths(vector<Path>&);

	vector<Path> paths;

private:
	int power;


};

