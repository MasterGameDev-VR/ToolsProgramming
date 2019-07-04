#include "stdafx.h"
#include "DiscreteGolfTableSolver.h"


/*
the program should act this way
- find the balls positions  col, row pairs
- find the holes positions  col, row pairs
- find the water hazard positions
- hit a ball towards a hole   
      which ball should be the first: the ball should be hit from the smallest number of
      possible launches and steps for launch to the highest: in this way we ensure ourselves
	  to start from the balls which could be displaced on the smallest area
-- choose the proper hole, depending on the possibility to reach it
--- distance of the ball from the hole, number of allowed steps and launches
-- when I find a ball that can't be associated to any of the remaining holes, I delete the last 
*/

/*
DATA TYPES

 std::pair<int, int> ball position col, row

std::pair < std::pair<int, int>, int >  ball position associated with the max number of shifts

 std::pair<int, int> holes positions col, row

 std::pair<int, int> water hazards positions col, row


*/
using namespace std;


DiscreteGolfTableSolver::DiscreteGolfTableSolver(string fileName)
{
	// loading data...
	ifstream inputFile;
	inputFile.open(fileName);
	filebuf* inputbuf = inputFile.rdbuf();
	streambuf* cinbuffer = cin.rdbuf(inputFile.rdbuf());

	cin >> width >> height; cin.ignore();
	for (int i = 0; i < height; i++) {
		std::string row;
		cin >> row; cin.ignore();
		table.append(row);
	}
	
	
}


DiscreteGolfTableSolver::~DiscreteGolfTableSolver()
{
}




void DiscreteGolfTableSolver::Execute() 
{
	Map mapInstance(width, height, table);

	mapInstance.PrintMap();
	//ricorsione per determinare tutte le traiettorie possibili per ciascuna pallina
	//a prescindere dalle possibili intersezioni tra esse
	mapInstance.BuildAllPaths(); 
	//algoritmo di backtracking che assembla alcune di esse in una soluzione ammissibile
	mapInstance.SearchValidPaths();

	mapInstance.PrintMap();
}
