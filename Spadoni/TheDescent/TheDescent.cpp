#include "TheDescent.h"
#include <iostream>
#include <fstream>
#include <algorithm>

TheDescent::TheDescent(std::string filePath)
{
	std::ifstream inputFile;
	inputFile.open(filePath);

	std::string line;
	if (!inputFile.is_open())
	{
		throw std::runtime_error("file not found!");
	}

	// mountains setup
	while (std::getline(inputFile, line))
	{
		int move = std::stoi(line);
		_mountains.push_back(move);
	}

	inputFile.close();
}

void TheDescent::Execute()
{
	// game loop
	for (int i = 9; i >= 2; i--) {
		auto it = std::max_element(_mountains.begin(), _mountains.end());
		_mountains[it - _mountains.begin()] = 0;

		it = std::max_element(_mountains.begin(), _mountains.end());
		if (*it >= i)
		{
			throw std::runtime_error("Defeat!");
		}
	}

	std::cout << "Victory!" << std::endl;
}

TheDescent::~TheDescent()
{
}
