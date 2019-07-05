#pragma once

class Ball : public MapObject
{
public:
	Ball(int, int, int);
	~Ball();

	int GetPower();
	void LoadPaths(std::vector<Path*>);

	std::vector<Path*> paths;

private:
	int power;


};

