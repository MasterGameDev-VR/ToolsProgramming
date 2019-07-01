#pragma once
#include <vector>
#include <set>
#include<iterator>
#include "Ball.h"
#include "Hole.h"

#include "DiscreteGolfTableSolver.h"

using namespace std;
class Map
{
public:
	Map(int, int, std::string&);
	~Map();

	//BuildAllPaths è un metodo che costruisce le traiettorie 
	//per ciascuno degli oggetti di tipo Ball nel container std::vector<Ball>
	void BuildAllPaths();
	//BuildPossiblePathsOfOneBall è un metodo ricorsivo che costruisce
	//tutte le traiettorie per una sola Ball
private:

	vector<Ball> balls;
	vector <Hole> holes;
	std::string map_table_str;
	std::vector<MapObject> map_table;
	int dim[2];

	void LoadMap();

	Directions RevertDirection(Directions);

	std::vector<Path>& BuildPossiblePathsOfOneBall(int, Path&&, Directions);
	Path&& CheckMove(Path&, Directions, int);

	MapObject&& GetDirectionModifier(Directions);

	bool IsInTheMap(MapObject&);

};

