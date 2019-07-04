#pragma once
#include <iostream>
#include <ostream>




class Map
{
public:
	Map(int, int, std::string&);
	~Map();

	//BuildAllPaths è un metodo che costruisce le traiettorie 
	//per ciascuno degli oggetti di tipo Ball nel container std::vector<Ball>
	void BuildAllPaths();
	
	void SearchValidPaths();
	
	std::string* GetMapTableString();
	int GetWidth();
	int GetHeight();

	void PrintMap();
	
	std::vector<MapObject*> map_table;

private:

	std::vector<Ball*> balls;
	std::vector<Hole*> holes;
	std::string map_table_str;
	int dim[2];

	void LoadMap();

	Directions RevertDirection( Directions );

	//BuildPossiblePathsOfOneBall è un metodo ricorsivo che costruisce
	//tutte le traiettorie per una sola Ball
	std::vector<Path>* BuildPossiblePathsOfOneBall(int, Path&, Directions);
	//il metodo CheckMove costruisce i singoli segmenti rettilinei di traiettoria
	Path& CheckMove(Path&, Directions, int);

	bool ImplementPath(Path&);
	bool MakeLine(Path&, int);

	MapObject& GetDirectionModifier(Directions);
	MapObject directionModifier = MapObject(0,0,true);

	bool IsInTheMap(MapObject*);

};

