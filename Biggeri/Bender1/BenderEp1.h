#pragma once
#include "BenderStatus.h"
class BenderEp1
{
public:
	BenderEp1(std::string filePath);
	void Execute();

private:
	std::string file="";
	std::vector<std::vector<char>> map;
	std::vector<std::pair<int, int>> teleporters;
	std::vector<std::string> moves;

	std::vector<BenderStatus> OldStatuses;
	BenderStatus currentStatus;
	bool alive = true;
	bool isLoop = false;

};

