#include "stdafx.h"
#include "Map.h"

struct SortPaths {
	bool operator() (Path& first_path, Path& second_path)
	{
		return (first_path.GetHolePtr()->GetWeight() < second_path.GetHolePtr()->GetWeight());
	}
};

struct SortBalls {
	bool operator() (Ball& first_ball, Ball& second_ball)
	{
		return (first_ball.paths.size() < second_ball.paths.size());
	}
};

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
			else if (content ==HAZARD)
			{
				map_table.push_back(WaterHazard(j, i));

			}
			
			else if (content == EMPTY) {
				map_table.push_back(MapObject(j, i,true));
			}
			
		}
	}
}

std::vector<Path>& Map::BuildPossiblePathsOfOneBall(int power, Path& pathToExtend, Directions direction = Directions::none) {
	
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
		if (!(newPath.IsValid())) 
		{
			continue;
		}
		if (newPath.IsFinished()) 
		{
			outputPaths.push_back(newPath);
			continue;
		}
		if (power == 1) 
		{
			continue;
		}
		outputPaths.emplace_back(BuildPossiblePathsOfOneBall(power - 1, newPath, (*it)));
	}
	
	return outputPaths;
}

//questo metodo estende la traiettoria dopo aver effettuato i vari test nel punto finale
//la invalida, se necessario
Path& Map::CheckMove(Path& pathToExtend, Directions directionToFollow, int currentPower) 
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
			Hole* holePtr =dynamic_cast<Hole*>(&map_table[lastPoint.GetRow() *dim[0] + lastPoint.GetCol()]);
			Ball* ballPtr = dynamic_cast<Ball*>(&map_table[lastPoint.GetRow() *dim[0] + lastPoint.GetCol()]);
			WaterHazard* waterHazardPtr= dynamic_cast<WaterHazard*>(&map_table[lastPoint.GetRow() *dim[0] + lastPoint.GetCol()]);
			if (holePtr != nullptr)
			{
				pathToExtend.ReachHole(newPoint, directionToFollow, holePtr);
			}
			else if (ballPtr != nullptr || waterHazardPtr!= nullptr)
			{	
				pathToExtend.Invalidate();
			}
		}
			
	}
	return pathToExtend;
}

void Map::BuildAllPaths() 
{
	for (unsigned int i = 0; i < balls.size(); i++) {
		std::vector<MapObject> startPoint;
		startPoint.push_back(MapObject(balls[i].GetCol(),balls[i].GetRow(),false));
		Path startPath(startPoint);
		std::vector<Path> paths = BuildPossiblePathsOfOneBall(balls[i].GetPower(), startPath);
		balls[i].LoadPaths(paths);

	}
	vector<Ball> ballsWithOnlyOnePath;
	vector<Ball> ballsWithWeightOnePath;
	vector<Ball> otherBalls;

	SortPaths comparePathsByHoleWeightsOperator;
	SortBalls compareBallsByNumberOfPaths;
	for (unsigned int i = 0; i < balls.size(); i++) {
		sort(balls[i].paths.begin(), balls[i].paths.end(), comparePathsByHoleWeightsOperator);
		if (balls[i].paths.size() == 1) {
			ballsWithOnlyOnePath.push_back(balls[i]);
			continue;
		}
		if (balls[i].paths[0].GetHolePtr()->GetWeight() == 1) {
			ballsWithWeightOnePath.push_back(balls[i]);
			continue;
		}
		otherBalls.push_back(balls[i]);
	}
	sort(otherBalls.begin(), otherBalls.begin(), compareBallsByNumberOfPaths);
	balls.assign(ballsWithOnlyOnePath.begin(), ballsWithOnlyOnePath.end());
	balls.insert(balls.end(),ballsWithWeightOnePath.begin(), ballsWithWeightOnePath.end());
	balls.insert(balls.end(), otherBalls.begin(), otherBalls.end());

};
bool Map::MakeLine(Path& pathToReadLineFrom, int moveNmbr) {
	Directions moveDir = pathToReadLineFrom.GetDirections()[moveNmbr];
	MapObject beginPoint =pathToReadLineFrom.GetPositions()[moveNmbr];
	MapObject endPoint = pathToReadLineFrom.GetPositions()[moveNmbr+1];
	MapObject nowPoint = beginPoint;
	while (nowPoint.GetCol() != endPoint.GetCol() || nowPoint.GetRow() != endPoint.GetRow()) 
	{

	}
	return true;
}

bool Map::ImplementPath(Path& pathToImplement) {
	for (unsigned int i = 0; i < pathToImplement.GetPositions().size(); i++) 
	{

	}
	return true;
}

void Map::SearchValidPaths() 
{
	int ballsIndex=0;
	int pathsIndex = 0;
	std::vector<std::pair<int, Path&>> revertData;
	while (0 <= ballsIndex && ballsIndex < balls.size()) 
	{
		if (pathsIndex >= balls[ballsIndex].paths.size()) {
			if (revertData.size() == 0)
				break;
			continue;
		}

		bool stepValid = false;
		if (balls[ballsIndex].paths[pathsIndex].GetHolePtr()->IsFilled())
		{
			stepValid = false;
		}
		else 
		{
			stepValid = true;
		}
		if (stepValid) {

			ballsIndex += 1;
			pathsIndex = 0;
			continue;
		}
		else {
			pathsIndex += 1;
		}
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

