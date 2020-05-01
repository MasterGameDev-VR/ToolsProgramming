#include "HorseRacingDuals.h"
#include <iostream>
#include <fstream>
#include <algorithm>

HorseRacingDuals::HorseRacingDuals(std::string fileName)
{
	std::ifstream in(fileName);
	auto inputBuf = std::cin.rdbuf(in.rdbuf());

	std::cin >> horse_num; std::cin.ignore();

	int horse;
	for (int i = 0; i < horse_num; i++) {
		std::cin >> horse; std::cin.ignore();
		horses.push_back(horse);
	}
}

void HorseRacingDuals::Execute()
{
	std::sort(horses.begin(), horses.end());
	int min_dist = horses[horse_num - 1];
	for (int i = 1; i < horse_num; i++) {
		int dist = horses[i] - horses[i - 1];
		if (dist < min_dist)
			min_dist = dist;
	}

	std::cout << min_dist << std::endl;
}
