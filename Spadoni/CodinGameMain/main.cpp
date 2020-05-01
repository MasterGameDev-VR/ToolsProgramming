#include "pch.h"
#include <iostream>
#include <SkynetRevolution.h>

int main()
{
	try 
	{
		SkynetRevolution game1("Data//SkynetRevolution.txt");
		game1.Execute();
	}
	catch (std::runtime_error error)
	{
		std::cout << error.what() << std::endl;
	}

	return 0;
}