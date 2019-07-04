#pragma once

class MapObject
{
public:
	MapObject(int, int, bool);

	virtual ~MapObject();
	virtual int GetCol();
	virtual int GetRow();
	virtual bool GetIsEmpty();

private:
	int x;
	int y;
	bool isEmpty;
};

