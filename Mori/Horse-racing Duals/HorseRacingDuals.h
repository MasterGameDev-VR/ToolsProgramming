#pragma once
#include <string>
#include <vector>

class HorseRacingDuals {
public:
	HorseRacingDuals(std::string fileName);
	void Execute();
private:
	int horse_num;
	std::vector<int> horses;
};