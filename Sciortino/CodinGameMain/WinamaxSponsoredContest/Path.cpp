#include "stdafx.h"
#include "Path.h"


Path::Path(std::vector<MapObject>& pathMapObjects_init): pathMapObjects(pathMapObjects_init)
{
}

Path::Path(std::vector<MapObject> pathMapObjects_init) : pathMapObjects(pathMapObjects_init)
{
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

std::vector<MapObject> Path::GetPath() {
	return pathMapObjects;
}

MapObject& Path::GetEndPoint(){
	return pathMapObjects.back();
}