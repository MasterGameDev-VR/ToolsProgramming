#pragma once
#include <iostream>
#include <string>
#include <vector>
class BenderStatus
{
	public:

	int BenderX = 0;
	int BenderY = 0;
	bool inverted = false;
	bool beerMode = false;
	std::string direction = "SOUTH";
	int distruction_count=0;
	BenderStatus(int x = 0, int y = 0, bool i = false, bool b = false, std::string dir = "SOUTH", int distruct = 0);
	bool Equals(BenderStatus other);
	std::string ToString();
	static std::pair<int, int> GetDirInt(std::string direction);
	void ChangeDir(std::vector<std::vector<char>>& map);

};

