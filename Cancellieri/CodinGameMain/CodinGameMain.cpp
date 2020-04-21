// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>

#include "../StockExchangeLosses/StockExchangeLosses.h"
#include "../War/War.h"
#include "CodinGameMain.h"

#define MAXTESTS1 6
#define MAXTESTS2 6

size_t ChooseTestID(size_t maxID)
{
	size_t testValue = 0;
	char input;

	while (true)
	{
		std::cout << "Run all tests? [y/n] : ";
		std::cin >> input; std::cin.ignore();

		switch (input)
		{
		case 'y':
			return testValue;
			break;
		case 'n':
			std::cout << "Insert test ID - from 1 to " + std::to_string(maxID) + " : ";
			std::cin >> testValue; std::cin.ignore();

			if (testValue > 0 && testValue <= maxID)
				return testValue;
			break;
		default:
			std::cout << "Wrong test ID, try again" << std::endl;
			break;
		}

	}
}


void StockExchangeLossesProgram()
{
	size_t testID = ChooseTestID(MAXTESTS1);

	if (testID == 0)
	{
		for (size_t i = 1; i <= MAXTESTS1; i++)
		{
			StockExchangeLosses program{ "..\\StockExchangeLosses\\Tests\\StockExchangeLosses_test_" + std::to_string(i) + ".txt" };
			program.Execute();
		}
	}
	else
	{
		StockExchangeLosses program{ "..\\StockExchangeLosses\\Tests\\StockExchangeLosses_test_" + std::to_string(testID) + ".txt" };
		program.Execute();
	}
}


void WarProgram()
{
	size_t testID = ChooseTestID(MAXTESTS2);

	if (testID == 0)
	{
		for (size_t i = 1; i <= MAXTESTS2; i++)
		{
			War program{ "..\\War\\Tests\\War_test_" + std::to_string(i) + ".txt" };
			program.Execute();
		}
	}
	else
	{
		War program{ "..\\War\\Tests\\War_test_" + std::to_string(testID) + ".txt" };
		program.Execute();
	}
}


int main()
{
	std::streambuf* buffer = std::cin.rdbuf();
	
	std::cout << "CodingGame - Andrea Cancellieri" << std::endl << std::endl;

	while (true)
	{
		std::cin.rdbuf(buffer);

		std::cout << "1 - Stock Exchange Losses" << std::endl;
		std::cout << "2 - War" << std::endl;
		std::cout << "0 - Quit Program" << std::endl << std::endl;

		std::cout << "Insert an ID to start a program: ";
		size_t selection;
		std::cin >> selection;

		switch (selection)
		{
		case 0:
			return 0;
		case 1:
			StockExchangeLossesProgram();
			break;
		case 2:
			WarProgram();
			break;
		default:
			std::cout << "Wrong ID, try again" << std::endl;
			break;
		}
		std::cout << std::endl;
	}
}
