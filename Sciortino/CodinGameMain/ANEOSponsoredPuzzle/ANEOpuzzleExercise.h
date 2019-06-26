#pragma once
#ifdef ANEOSPONSOREDPUZZLE_EXPORTS
#define ANEOSPONSOREDPUZZLE_API __declspec(dllexport)
#else
#define ANEOSPONSOREDPUZZLE_API __declspec(dllimport)
#endif
/*
class ANEOSPONSOREDPUZZLE_API mystring : public std::string
{};

class ANEOSPONSOREDPUZZLE_API myIntVector : public std::vector<int>
{};
class ANEOSPONSOREDPUZZLE_API myFloatVector : public std::vector<float>
{};
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
extern "C++"  class ANEOSPONSOREDPUZZLE_API ANEOpuzzleExercise

{
public:
	ANEOpuzzleExercise(std::string);
	~ANEOpuzzleExercise();

	void Execute();
private:
	bool CheckIfTheIthTrafficLightIsGreen(std::vector<float>&, std::vector<int>&, unsigned int);

};

