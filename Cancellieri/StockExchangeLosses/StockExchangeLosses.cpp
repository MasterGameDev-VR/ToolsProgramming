// StockExchangeLosses.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "StockExchangeLosses.h"


StockExchangeLosses::StockExchangeLosses(std::string testFile)
{
	std::ifstream in(testFile);
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	std::cin >> n; std::cin.ignore();

	// allocate enough space on the vector
	stockValues = new std::vector<size_t>(n);

	size_t value;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> value; std::cin.ignore();
		stockValues->at(i) = value;
	}
}

void StockExchangeLosses::Execute()
{
	int maxLoss = 0;
	int tempMaxLoss = 0;
	size_t maxValue = stockValues->at(0);

	for (size_t i = 1; i < n; i++)
	{
		// store the max value if found
		if (stockValues->at(i) > maxValue)
			maxValue = stockValues->at(i);
		// check if there's a loss (possible maxLoss)
		else if (stockValues->at(i) < stockValues->at(i-1))
		{
			tempMaxLoss = stockValues->at(i) - maxValue;
			// calculate maxLoss if found
			if (tempMaxLoss < maxLoss)
				maxLoss = tempMaxLoss;
		}
	}

	std::cout << std::endl << "Max Loss = " << maxLoss << std::endl;
	std::cout << std::endl << "===================================" << std::endl;

	::operator delete[](stockValues);
}
