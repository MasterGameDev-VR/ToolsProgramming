#pragma once
#include <vector>
#include "DiscreteGolfTableSolver.h"
#include "MapObject.h"
#include "Hole.h"
using namespace std;
class Path
{
public:
	Path(std::vector<MapObject>&);
	Path(std::vector<MapObject>);

	~Path();

	
	

	void AddPointObject(MapObject&, Directions);
	void ReachHole(MapObject&, Directions, Hole*);

	void Invalidate();
	bool IsFinished();

	std::vector<MapObject> GetPath();

	MapObject& GetEndPoint();

private:
	std::vector<MapObject> pathMapObjects;
	std::vector<Directions> directions;
	Hole* pathEndHole = nullptr;
	bool isValid = true;
};

