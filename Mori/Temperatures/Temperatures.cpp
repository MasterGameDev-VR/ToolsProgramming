#include "Temperatures.h"
#include <iostream>
#include <fstream>

Temperatures::Temperatures(std::string fileName)
{
	std::ifstream in(fileName);
	auto inputBuf = std::cin.rdbuf(in.rdbuf());

	std::cin >> temp_num; std::cin.ignore();

	int temp;
	for (int i = 0; i < temp_num; i++) {
		std::cin >> temp; std::cin.ignore();
		temps.push_back(temp);
	}
}

void Temperatures::Execute()
{
	int closest = MAX_TEMP;
	int temp;
	for (int i = 0; i < temp_num; i++) {
		temp = temps[i];
		if (abs(temp) < abs(closest))
			closest = temp;
		else if (abs(temp) == abs(closest))
			closest = abs(temp);
	}

	if (temp_num == 0)
		std::cout << 0 << std::endl;
	else
		std::cout << closest << std::endl;
}
