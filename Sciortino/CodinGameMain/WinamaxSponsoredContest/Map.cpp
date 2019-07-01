#include "stdafx.h"
#include "Map.h"


Map::Map(int width_init,int height_init, std::string& table_init)
{
	dim[0]=width_init;
	dim[1]=height_init;
	map_table_str = table_init;
	LoadMap();
}


Map::~Map()
{
}

void Map::LoadMap() {
	//span over the height, a single column, row index
	for (int i = 0; i < dim[1]; i++) { 
		//span over the width, a single row, column index
		for (int j = 0; i < dim[0]; j++) {
			char content = map_table_str[i*dim[0] + j];    //dim[0] is the width
			if (content == HOLE) {
				map_table.push_back(Hole(j, i));
				holes.push_back(Hole(j, i));
			}
			else if (isdigit(content))
			{
				map_table.push_back(Ball(j, i,atoi(&content) ) );
				balls.push_back(Ball(j, i, atoi(&content)));
			}
			
			else {
				map_table.push_back(MapObject(j, i,true));
			}
			
		}
	}
}

std::vector<Path>& Map::BuildPossiblePathsOfOneBall(int power, Path&& pathToExtend, Directions direction = Directions::none) {
	
	std::set<Directions> possibleDirections;
	possibleDirections.insert({ Directions::up ,Directions::down, Directions::right, Directions::left });
	if (direction != Directions::none) {
		possibleDirections.erase(RevertDirection(direction));
	}
	
	std::vector<Path> outputPaths;
	for (auto it = possibleDirections.begin(); it!=possibleDirections.end(); it++)
	{
		Path clonedPath(pathToExtend.GetPath());
		Path newPath = CheckMove(clonedPath, (*it), power);
	}
	return outputPaths;
}

Path&& Map::CheckMove(Path& pathToExtend, Directions directionToFollow, int currentPower) 
{
	MapObject directionModifier = GetDirectionModifier(directionToFollow);
	MapObject lastPoint = pathToExtend.GetEndPoint();
	MapObject newPoint(lastPoint.GetCol() + currentPower * directionModifier.GetCol(), lastPoint.GetRow() + currentPower * directionModifier.GetRow(), false);
	if (!IsInTheMap(newPoint)) 
	{
		pathToExtend.Invalidate();
	}
	else 
	{
		if (map_table[lastPoint.GetRow() *dim[0] + lastPoint.GetCol()].GetIsEmpty()) 
		{
			pathToExtend.AddPointObject(newPoint, directionToFollow);
		}
		else
		{

		}
			
	}
}

void Map::BuildAllPaths() 
{
	for (unsigned int i = 0; i < balls.size(); i++) {
		std::vector<MapObject> startPoint;
		startPoint.push_back(MapObject(balls[i].GetCol(),balls[i].GetRow(),false));
		std::vector<Path> paths = BuildPossiblePathsOfOneBall(balls[i].GetPower(), Path(startPoint));
		balls[i].LoadPaths(paths);
	}

}

Directions Map::RevertDirection(Directions direction) 
{
	Directions output;
	switch (direction) 
	{
	case Directions::down:
		output = Directions::up;
		break;
	case Directions::up:
		output = Directions::down;
		break;
	case Directions::right:
		output = Directions::left;
		break;
	case Directions::left:
		output = Directions::right;
		break;
	case Directions::none:
		output = Directions::none;
		break;
	default:
		output = Directions::none;
		break;
	}
	return output;
}

MapObject&& Map::GetDirectionModifier(Directions direction) 
{
	int col_shift = 0;
	int row_shift = 0;
	switch (direction)
	{
	case Directions::down:
		row_shift = 1;
		break;
	case Directions::up:
		row_shift = -1;
		break;
	case Directions::right:
		col_shift = 1;
		break;
	case Directions::left:
		col_shift = -1;
		break;
	case Directions::none:
		break;
	default:
		break;
	}
	return MapObject(col_shift, row_shift,true);
}
bool Map::IsInTheMap(MapObject& pointObject) {
	return (pointObject.GetCol() >= 0 && pointObject.GetCol() < dim[0] && pointObject.GetRow() >= 0 && pointObject.GetRow() < dim[1]);
}