#pragma once

class Ball;
class Map;

class Path
{
public:
	explicit Path(std::vector<MapObject*>&, std::vector<Directions*>&,Hole*, bool);
	/*
	explicit Path(const  Path& );
	explicit Path(Path&&);

	Path& operator=(const Path&);
	Path& operator=( Path&&);
	*/
	~Path();


	void AddPointObject(MapObject*, Directions*);
	void ReachHole(MapObject*, Directions*, Hole*);

	void Invalidate();
	bool IsFinished();
	bool IsValid();

	Hole* GetHolePtr();

	Path& GetPath();

	MapObject* GetEndPoint();

	std::vector<MapObject*>& GetPositions();
	std::vector<Directions*>& GetDirections();

	void Restore(Map&);
	void BackUp(int,int,char);

private:
	std::vector<MapObject*> pathMapObjects;
	std::vector<Directions*> directions;
	Hole* pathEndHole = nullptr;
	bool isValid = true;

	std::vector<std::pair<std::pair<int, int>, char>> backupMapObjs;
};

