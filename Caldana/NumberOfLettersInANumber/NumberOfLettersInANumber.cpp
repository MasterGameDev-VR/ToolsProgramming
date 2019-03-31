#include "stdafx.h"
#include "NumberOfLettersInANumber.h"

NumberOfLettersInANumberNS::NumberOfLettersInANumber::NumberOfLettersInANumber(std::string & fileName)
{
	SetValues(fileName);
}

void NumberOfLettersInANumberNS::NumberOfLettersInANumber::Execute()
{
	long long i = 0;
	long long counter;
	while (i < n)
	{
		counter = to_binary(start);
		if (start == counter)
			break;
		start = counter;
		i++;
	}
	std::cout << start << std::endl;
}

long long NumberOfLettersInANumberNS::NumberOfLettersInANumber::to_binary(long long a)
{
	long long counter = 0;
	long double log_n = log2(a);
	long long bit = floor(log2(a));
	for (long long i = bit; i >= 0; i--) {
		long long k = a >> i;
		if (k & 1)
			counter += 3;
		else
			counter += 4;
	}
	return counter;
}

void NumberOfLettersInANumberNS::NumberOfLettersInANumber::SetValues(std::string & fileName)
{
	std::ifstream input(fileName);
	auto cinbuf = std::cin.rdbuf(input.rdbuf());
	std::cin >> start >> n; std::cin.ignore();
}
