#pragma once
#include <string>
#include <vector>

class War
{
public:
	std::vector<int> deck1 = {};
	std::vector<int> deck2 = {};
	int rounds = 0;
	bool pat = false;

	int GetCardValue(std::string card);

	War(std::string filePath);
	void Execute();
};

