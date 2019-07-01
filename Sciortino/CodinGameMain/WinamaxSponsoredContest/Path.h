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
	Path( Path& );
	~Path();

	
	

	void AddPointObject(MapObject&, Directions);
	void ReachHole(MapObject&, Directions, Hole*);

	void Invalidate();
	bool IsFinished();
	bool IsValid();

	Hole* GetHolePtr();

	Path& GetPath();

	MapObject& GetEndPoint();

	std::vector<MapObject>& GetPositions();
	std::vector<Directions>& GetDirections();

private:
	std::vector<MapObject> pathMapObjects;
	std::vector<Directions> directions;
	Hole* pathEndHole = nullptr;
	bool isValid = true;
};

