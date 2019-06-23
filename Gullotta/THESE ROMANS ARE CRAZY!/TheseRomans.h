#pragma once

#include <string>

class TheseRomans
{
public:
	TheseRomans(std::string fileName);

	void Execute();

private:
	int num1, num2, sum;
	std::string rom1, rom2;

	int value(char v);
	int romanToInt(std::string romanStr);
	int digitHelper(char num1, char num2, int i, char *c);
	int digit(char ch, int n, int i, char *c);
	void print(int num);

};