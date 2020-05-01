#pragma once

#include <string>
#include <vector>

class ASCIIArt {
public:
	ASCIIArt(std::string fileName);
	void Execute();
private:
	int L, H;
	std::string T;
	std::vector<std::string> ROWS;
	std::vector<std::string> finalRows;
};