#pragma once
#include <string>
#include <vector>
#include <map>
#include "BenderState.h"

class BenderEpisode1 {
public:
	BenderEpisode1(std::string fileName);
	void Execute();
private:
	void Move();
	void Obstacle();
	bool IsInLoop();
private:
	std::vector<std::vector<char>> map;
	std::vector<std::pair<int, int>> teleporters;
	std::map<std::pair<int, int>, std::vector<BenderState>> visited;
	BenderState currentState;
};