#include "stdafx.h"
#include "SumofDivisors.h"


#include <iostream>
#include <fstream>
#include <iomanip> 


SumofDivisors::SumofDivisors(std::string fileName)
{
	//std::cout << fileName << std::endl;
	std::ifstream input(fileName);
	auto cinbuf = std::cin.rdbuf(input.rdbuf());
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();

}

long double SumofDivisors::divisorSum(int num)
{
	long double sum = 0;

	for (int i = 1; i <= num; ++i) {


		for (int j = 1; j * j <= i; ++j) {
			if (i % j == 0) {
				if (i / j == j)
					sum += j;
				else
					sum += j + i / j;
			}
		}
	}
	return sum;
}

void SumofDivisors::Execute()
{
	std::cout << std::setprecision(10);
	std::cout << "La somma dei divisori di " << n << " e': " << divisorSum(n) << std::endl;
}
