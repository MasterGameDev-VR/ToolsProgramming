#include "stdafx.h"
#include "Path.h"


Path::Path(std::vector<MapObject*>& pathMapObjects_init,std::vector<Directions*>& directions_init, Hole* endHolePtr_init, bool isValid_init): 
	pathMapObjects(pathMapObjects_init),
	directions(directions_init),
	pathEndHole(endHolePtr_init),
	isValid(isValid_init)
{
}
/*
Path::Path(const Path& path_init) {
	pathMapObjects = path_init.pathMapObjects;
	directions = path_init.directions;
	pathEndHole = path_init.pathEndHole;
	isValid = path_init.isValid;
}

Path::Path(Path&& path_init) {
	std::swap(pathMapObjects, path_init.pathMapObjects);
	std::swap(directions, path_init.directions);
	std::swap(pathEndHole, path_init.pathEndHole);
	std::swap(isValid, path_init.isValid);
}

Path& Path::operator=(const Path& path_init) {
	if (&path_init != this) {
		pathMapObjects = path_init.pathMapObjects;
		directions = path_init.directions;
		pathEndHole = path_init.pathEndHole;
		isValid = path_init.isValid;
	}

	return *this;
}

Path& Path::operator=(Path&& path_init) {
	if (&path_init != this) {
		std::swap(pathMapObjects, path_init.pathMapObjects);
		std::swap(directions,path_init.directions);
		std::swap(pathEndHole, path_init.pathEndHole);
		std::swap(isValid, path_init.isValid);
		//pathMapObjects = path_init.pathMapObjects;
		//directions = path_init.directions;
		//pathEndHole = path_init.pathEndHole;
		//isValid = path_init.isValid;
	}
	return *this;
}
*/
Path::~Path()
{
}

void Path::AddPointObject(MapObject* newMapPointObject, Directions* newDirection) 
{
	pathMapObjects.push_back(newMapPointObject);
	directions.push_back(newDirection);
}
void Path::ReachHole(MapObject* newMapPointObject, Directions* newDirection, Hole* newPathEndHole) {
	AddPointObject(newMapPointObject, newDirection);
	pathEndHole = newPathEndHole;
}
void Path::Invalidate() {
	isValid = false;
}

void Path::Validate() {
	isValid = true;
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

MapObject* Path::GetEndPoint(){
	return pathMapObjects.back();
}

Hole* Path::GetHolePtr() {
	return pathEndHole;
}

std::vector<MapObject*>& Path::GetPositions() {
	return pathMapObjects;
}
std::vector<Directions*>& Path::GetDirections() {
	return directions;
}

void Path::Restore(Map& mapToRestore) {
	std::string* map_table_str_ptr = mapToRestore.GetMapTableString();
	int width = mapToRestore.GetWidth();
	int height = mapToRestore.GetHeight();
	for ( int i = 0; i < backupMapObjs.size(); i++)
	{
		int col_index = backupMapObjs[i].first.first;

		int row_index = backupMapObjs[i].first.second;
		//map_table_str_ptr->replace(row_index*width + col_index, 1, &backupMapObjs[i].second);
		mapToRestore.WriteMapTableString(row_index*width + col_index, backupMapObjs[i].second);
	}
	backupMapObjs.clear();
}
void Path::BackUp(int col_index, int row_index, char content) {
	std::pair<int, int> position = std::make_pair(col_index, row_index);
	std::pair<std::pair<int, int>, char> backupMapObj = std::make_pair(position, content);
	backupMapObjs.push_back(backupMapObj);
}