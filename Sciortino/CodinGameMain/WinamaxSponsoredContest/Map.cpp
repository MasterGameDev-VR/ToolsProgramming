#include "stdafx.h"
#include "Map.h"
using namespace std;
struct SortPaths {
	bool operator() (Path* first_path, Path* second_path)
	{
		return (first_path->GetHolePtr()->GetWeight() < second_path->GetHolePtr()->GetWeight());
	}
};

struct SortBalls {
	bool operator() (Ball* first_ball, Ball* second_ball)
	{
		return ((first_ball->paths).size() < (second_ball->paths).size());
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
	//span over the height,takes a single row (not in a single column), row index
	for (int i = 0; i < dim[1]; i++) { 
		//span over the width, in a single row, column index
		for (int j = 0; j < dim[0]; j++) {
			char content = map_table_str[i*dim[0] + j];    //dim[0] is the width
			if (content == HOLE) {
				Hole* hole = new Hole(j, i);
				map_table.push_back(hole);
				holes.push_back(hole);
			}
			else if (isdigit(content))
			{
				Ball* ball = new Ball(j, i, atoi(&content));
				map_table.push_back(ball);
				balls.push_back(ball);
			}
			else if (content ==HAZARD)
			{
				WaterHazard* waterHazard = new WaterHazard(j, i);
				map_table.push_back(waterHazard);

			}
			
			else if (content == EMPTY) {
				MapObject* emptyMapObject = new MapObject(j, i, true);
				map_table.push_back(emptyMapObject);
			}
			
		}
	}
}

std::vector<Path*> Map::BuildPossiblePathsOfOneBall(int power, Path* pathToCopy, Directions direction = Directions::none) {
	
	std::set<Directions> possibleDirections;
	possibleDirections.insert({ Directions::up ,Directions::down, Directions::right, Directions::left });
	if (direction != Directions::none) {
		possibleDirections.erase(RevertDirection(direction));
	}
	
	std::vector<Path*>* outputPaths= new std::vector<Path*>();
	for (auto it = possibleDirections.begin(); it!=possibleDirections.end(); it++)
	{
		Path* newPathDuplicate = new Path(*pathToCopy);
		newPathDuplicate = new Path(CheckMove(*newPathDuplicate, (*it), power));
		if (!(newPathDuplicate->IsValid()))
		{
			continue;
		}
		if (newPathDuplicate->IsFinished())
		{
			outputPaths->push_back(newPathDuplicate);
			continue;
		}
		if (power == 1) 
		{
			continue;
		}
		std::vector<Path*> outputPathsFromRecursion = BuildPossiblePathsOfOneBall(power - 1, newPathDuplicate, (*it));
		for (auto itRec = outputPathsFromRecursion.begin(); itRec != outputPathsFromRecursion.end(); itRec++) {
			outputPaths->push_back(*itRec);
		}

	}
	
	return *outputPaths;
}

//questo metodo estende la traiettoria dopo aver effettuato i vari test nel punto finale
//la invalida, se necessario
Path& Map::CheckMove(Path& pathToExtend, Directions directionToFollow, int currentPower) 
{
	GetDirectionModifier(directionToFollow);
	MapObject* lastPoint = pathToExtend.GetEndPoint();
	MapObject* newPoint= new MapObject(lastPoint->GetCol() + currentPower * directionModifier.GetCol(), lastPoint->GetRow() + currentPower * directionModifier.GetRow(), false);
	Directions* newDirection = new Directions(directionToFollow);
	if (!IsInTheMap(newPoint)) 
	{
		pathToExtend.Invalidate();
	}
	else 
	{
		int newPointIndex= newPoint->GetRow() *dim[0] + newPoint->GetCol();
		if (map_table[newPointIndex]->GetIsEmpty())
		{
			pathToExtend.Validate();
			pathToExtend.AddPointObject(newPoint, newDirection);
		}
		else
		{
			Hole* holePtr =dynamic_cast<Hole*>(map_table[newPointIndex]);
			Ball* ballPtr = dynamic_cast<Ball*>(map_table[newPointIndex]);
			WaterHazard* waterHazardPtr= dynamic_cast<WaterHazard*>(map_table[newPointIndex]);
			if (holePtr != nullptr)
			{
				pathToExtend.Validate();
				pathToExtend.ReachHole(newPoint, newDirection, holePtr);
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
		std::vector<MapObject*>* startPoint = new std::vector<MapObject*>();
		startPoint->push_back(new MapObject((*balls[i]).GetCol(), (*balls[i]).GetRow(),false));
		std::vector<Directions*> startDirection;
		Path* startPath= new Path((*startPoint), startDirection,nullptr,true);
		std::vector<Path*> paths = BuildPossiblePathsOfOneBall(balls[i]->GetPower(), startPath);
		balls[i]->LoadPaths(paths);

	}
	std::vector<Ball*> ballsWithOnlyOnePath;
	std::vector<Ball*> ballsWithWeightOnePath;
	std::vector<Ball*> otherBalls;

	SortPaths comparePathsByHoleWeightsOperator;
	SortBalls compareBallsByNumberOfPaths;
	for (unsigned int i = 0; i < balls.size(); i++) {
		sort((balls[i]->paths).begin(), (balls[i]->paths).end(), comparePathsByHoleWeightsOperator);
		if ((balls[i]->paths).size() == 1) {
			ballsWithOnlyOnePath.push_back(balls[i]);
			continue;
		}
		Hole* holePtr= (*(balls[i]->paths).begin())->GetHolePtr();
		if (holePtr != nullptr) {
			int myweightt = holePtr->GetWeight();
			if (myweightt == 1) {
				ballsWithWeightOnePath.push_back(balls[i]);
				continue;
			}
		}
		
		otherBalls.push_back(balls[i]);
	}
	sort(otherBalls.begin(), otherBalls.end(), compareBallsByNumberOfPaths);
	balls.assign(ballsWithOnlyOnePath.begin(), ballsWithOnlyOnePath.end());
	balls.insert(balls.end(),ballsWithWeightOnePath.begin(), ballsWithWeightOnePath.end());
	balls.insert(balls.end(), otherBalls.begin(), otherBalls.end());

};
bool Map::MakeLine(Path* pathToReadLineFrom, int moveNmbr) {
	Directions moveDir = *pathToReadLineFrom->GetDirections()[moveNmbr];
	GetDirectionModifier(moveDir);
	MapObject beginPoint =*pathToReadLineFrom->GetPositions()[moveNmbr];
	MapObject endPoint = *pathToReadLineFrom->GetPositions()[moveNmbr+1];
	MapObject nowPoint = beginPoint;

	int row_now = nowPoint.GetRow();
	int col_now = nowPoint.GetCol();
	while (col_now != endPoint.GetCol() || row_now != endPoint.GetRow())
	{

		if (map_table_str[row_now*dim[0] + col_now] == HOLE)
		{
			return false;
			/*
			if (col_now == endPoint.GetCol() && row_now == endPoint.GetRow())
			{
				pathToReadLineFrom->BackUp(col_now, row_now, map_table_str[row_now*dim[0] + col_now]);
				map_table_str[row_now*dim[0] + col_now] = 'o';
				return true;
			}
			else {
				return false;
			}
			*/
		}
		pathToReadLineFrom->BackUp(col_now, row_now, map_table_str[row_now*dim[0] + col_now]);
		map_table_str[row_now*dim[0] + col_now] = (char)moveDir;

		nowPoint = MapObject(nowPoint.GetCol() + directionModifier.GetCol(), nowPoint.GetRow() + directionModifier.GetRow(), false);
		row_now = nowPoint.GetRow();
		col_now = nowPoint.GetCol();
		
		if (isdigit(map_table_str[row_now*dim[0] + col_now])) {
			return false;
		}
		if (map_table_str[row_now*dim[0] + col_now] == (char)Directions::up) {
			return false;
		}
		if (map_table_str[row_now*dim[0] + col_now] == (char)Directions::down) {
			return false;
		}
		if (map_table_str[row_now*dim[0] + col_now] == (char)Directions::right) {
			return false;
		}
		if (map_table_str[row_now*dim[0] + col_now] == (char)Directions::left) {
			return false;
		}
		
	}
	return true;
}

bool Map::ImplementPath(Path* pathToImplement) {
	for (unsigned int moveNmbr = 0; moveNmbr < pathToImplement->GetDirections().size(); moveNmbr++)
	{
		bool success = MakeLine(pathToImplement, moveNmbr);
		if (!success) 
		{
			pathToImplement->Restore(*this);
			return false;
		}
	}
	return true;
}

void Map::SearchValidPaths() 
{
	unsigned int ballsIndex=0;
	unsigned int pathsIndex = 0;
	std::vector<std::pair<int, Path*>> toRevertPaths;
	while (0 <= ballsIndex && ballsIndex < balls.size()) 
	{
		if (pathsIndex >= (balls[ballsIndex]->paths).size()) {
			if (toRevertPaths.size() == 0) 
			{
				break;
			}
			std::pair<int, Path*> toRevertPath = toRevertPaths.back();
			toRevertPath.second->Restore(*this);
			toRevertPath.second->GetHolePtr()->Empty();
			//se la pallina in questione non ha nessun percorso che si può completare,
			//allora si inverte il percorso della pallina precedente (fatto nelle righe sopra)
			//e si torna a trovare un path per quest'ultima, partendo dal path candidato successivo
			// da cui gli indici che seguono
			ballsIndex -= 1;
			pathsIndex = toRevertPath.first + 1;

			toRevertPaths.pop_back();
			continue;
		}

		bool stepValid = false;
		if (  (balls[ballsIndex])->paths[pathsIndex]->GetHolePtr()->IsFilled())
		{
			stepValid = false;
		}
		else 
		{
			stepValid = ImplementPath((balls[ballsIndex])->paths[pathsIndex]);
		}
		if (stepValid) {
			(balls[ballsIndex])->paths[pathsIndex]->GetHolePtr()->Fill();
			toRevertPaths.push_back(std::make_pair(pathsIndex, (balls[ballsIndex])->paths[pathsIndex]));
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

MapObject& Map::GetDirectionModifier(Directions direction) 
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
	directionModifier = MapObject(col_shift, row_shift, true);
	return directionModifier;
}
bool Map::IsInTheMap(MapObject* pointObject) {
	return (pointObject->GetCol() >= 0 && pointObject->GetCol() < dim[0] && pointObject->GetRow() >= 0 && pointObject->GetRow() < dim[1]);
}

std::string* Map::GetMapTableString() {
	return &map_table_str;
}

int Map::GetWidth() {
	return dim[0];
}

int Map::GetHeight() {
	return dim[1];
}

void Map::PrintMap() 
{
	for (unsigned int i = 0; i < dim[1]; i++) {
		for (unsigned int j = 0; j < dim[0]; j++) {
			std::cout << map_table_str[i * dim[0] + j];
		}
		std::cout << endl;
	}
	std::cout << endl;
	std::cout << endl;
	std::cout << endl;
}
void Map::WriteMapTableString(int index, char content) {
	map_table_str[index] = content;

}

