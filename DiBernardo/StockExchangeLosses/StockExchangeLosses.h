#pragma once

#pragma once
#include <string>

#ifdef STOCKEXCHANGELOSSES_EXPORTS
#define DLLDIR  __declspec(dllexport) 

#else
#define DLLDIR  __declspec(dllimport) 

#endif

class DLLDIR StockExchangeLosses {

public:
	StockExchangeLosses(std::string fileName);

	void Execute();

private:

	std::string m_fileName;
};