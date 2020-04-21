#pragma once
#include <string>
#include <vector>

class Temperatures {
public:
	Temperatures(std::string fileName);
	void Execute();
private:
	const int MAX_TEMP = 5526;
	int temp_num;
	std::vector<int> temps;
};
