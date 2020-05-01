#pragma once

#include <vector>


#ifdef STOCKEXCHANGELOSSES_EXPORTS
#define STOCKEXCHANGELOSSES_API __declspec(dllexport)
#else
#define STOCKEXCHANGELOSSES_API __declspec(dllimport)
#endif

class StockExchangeLosses 
{
public:
	STOCKEXCHANGELOSSES_API StockExchangeLosses(std::string testFile);
	STOCKEXCHANGELOSSES_API void Execute();

private:
	// vector to store the stock values over time
	std::vector<size_t>* stockValues;

	// number of stock values
	size_t n;

};