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

#define UP '^'
#define DOWN 'v'
#define RIGHT '>'
#define LEFT '<'
#define NONE ' '

#define HOLE 'H'
#define HAZARD 'X'
#define EMPTY '.'

enum class Directions : char
{
	up = UP,
	down = DOWN,
	right = RIGHT,
	left = LEFT,
	none = NONE
};


extern "C++" class WINAMAXSPONSOREDCONTEST_API DiscreteGolfTableSolver
{
public:
	DiscreteGolfTableSolver(string);
	~DiscreteGolfTableSolver();

	void Execute();
private:

	


	int width;
	int height;
	//table or ground
	std::string table;


};



