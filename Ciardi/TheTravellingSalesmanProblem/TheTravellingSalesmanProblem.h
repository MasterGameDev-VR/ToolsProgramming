#pragma once

#include <string>
#include <vector>

class TheTravellingSalesmanProblem {
public:
	TheTravellingSalesmanProblem(std::string fileName);
	void Execute();
private:
	int FindNear(int position);
private:
	std::vector<std::pair<int, int>> cities;
};