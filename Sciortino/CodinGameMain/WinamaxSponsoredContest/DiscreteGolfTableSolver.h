#pragma once

#ifdef WINAMAXSPONSOREDCONTEST_EXPORTS
#define WINAMAXSPONSOREDCONTEST_API __declspec(dllexport)
#else
#define WINAMAXSPONSOREDCONTEST_API __declspec(dllimport)
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include<cctype>


extern "C++" class WINAMAXSPONSOREDCONTEST_API DiscreteGolfTableSolver
{
public:
	DiscreteGolfTableSolver(std::string);
	~DiscreteGolfTableSolver();

	void Execute();
private:

	


	int width;
	int height;
	//table or ground
	std::string table;


};



