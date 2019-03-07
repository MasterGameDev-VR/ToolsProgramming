// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "..\NumberOfLettersInANumber\NumberOfLettersInANumber.h"

int main()
{
	NumberOfLettersInANumberNS::NumberOfLettersInANumber instance("..\\Test\\NumberOfLettersInANumber_01.txt");
	instance.Execute();
}

