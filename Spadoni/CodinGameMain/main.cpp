#include "pch.h"
#include "IGame.h"
#include <iostream>
#include <SkynetRevolution.h>
#include <TheDescent.h>


int main()
{
	std::vector<std::string> tests;
	tests.push_back("Data//SkynetRevolution.txt");
	tests.push_back("Data//TheDescent_1.txt");
	tests.push_back("Data//TheDescent_2.txt");

	try 
	{
		for (int testIndex = 0; testIndex < tests.size(); testIndex++) {
			if (testIndex == 0) {
				IGame* game = new SkynetRevolution(tests[testIndex]);
				game->Execute();
			}
			else
			{
				IGame* game = new TheDescent(tests[testIndex]);
				game->Execute();
			}
		}
	}
	catch (std::runtime_error error)
	{
		std::cout << error.what() << std::endl;
	}

	std::cout << "Success!" << std::endl;
	return 0;
}