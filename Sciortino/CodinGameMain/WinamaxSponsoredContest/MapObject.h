#pragma once
class MapObject
{
public:
	MapObject(int, int, bool);

	~MapObject();
	int GetCol();
	int GetRow();
	bool GetIsEmpty();

private:
	int x;
	int y;
	bool isEmpty;
};

