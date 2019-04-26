#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

struct MayanNumber
{
	vector<string> digit;
};

class MayanCalculation
{
private:
	int L;
	int H;
	vector<MayanNumber> numbers;

	int S1;
	vector<MayanNumber> firstMayanNumber;

	int S2;
	vector<MayanNumber> secondMayanNumber;

public:
	MayanCalculation(char *fileName);

	void Execute();
};