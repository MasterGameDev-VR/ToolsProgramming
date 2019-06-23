#pragma once

#include <string>

class SumofDivisors
{
public:

	SumofDivisors(std::string fileName);

	void Execute();

private:

	int n;

	long double divisorSum(int num);

};