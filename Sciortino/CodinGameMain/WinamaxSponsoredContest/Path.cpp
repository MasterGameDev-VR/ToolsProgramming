#include "stdafx.h"
#include "Path.h"


Path::Path(std::vector<MapObject>& pathMapObjects_init): pathMapObjects(pathMapObjects_init)
{
}
Path::Path(Path& path_init) {
	pathMapObjects = path_init.pathMapObjects;
	directions = path_init.directions;
	pathEndHole = path_init.pathEndHole;
	isValid = path_init.isValid;
}

Path::~Path()
{
}

void Path::AddPointObject(MapObject& newMapPointObject, Directions newDirection) 
{
	pathMapObjects.push_back(newMapPointObject);
	directions.push_back(newDirection);
}
void Path::ReachHole(MapObject& newMapPointObject, Directions newDirection, Hole* newPathEndHole) {
	AddPointObject(newMapPointObject, newDirection);
	pathEndHole = newPathEndHole;
}
void Path::Invalidate() {
	isValid = false;
}
bool Path::IsFinished() {
	return (pathEndHole != nullptr);
}
bool Path::IsValid() 
{
	return isValid;
}

Path& Path::GetPath() {
	return *this;
}

MapObject& Path::GetEndPoint(){
	return pathMapObjects.back();
}

Hole* Path::GetHolePtr() {
	return pathEndHole;
}

std::vector<MapObject>& Path::GetPositions() {
	return pathMapObjects;
}
std::vector<Directions>& Path::GetDirections() {
	return directions;
}