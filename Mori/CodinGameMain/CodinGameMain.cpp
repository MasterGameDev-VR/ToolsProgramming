#include "../Temperatures/Temperatures.h"
#include <iostream>

int main()
{
	Temperatures temp("../Temperatures/TestCases/Temperatures_1.txt");
	temp.Execute();
}
