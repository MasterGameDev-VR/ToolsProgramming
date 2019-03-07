// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "..\NumberOfLettersInANumber\NumberOfLettersInANumber.h"
#include "..\NetworkCabling\NetworkCabling.h"

using namespace std;

int main()
{
	int choice;
	cout << "Riccardo Caldana - Master CGD 2018/2019 - Tools Programming Exam\n";
	cout << "Insert 1 to select NumberOfLetterInANumber\nInsert 2 to select NetworkCabling\n";
	cin >> choice;
	switch (choice) 
	{
	case 1:
	{
		NumberOfLettersInANumberNS::NumberOfLettersInANumber instance("..\\Test\\NumberOfLettersInANumber_01.txt");
		instance.Execute();
		break;
	}
	case 2:
	{
		NetworkCablingNS::NetworkCabling instance1("..\\Test\\NetworkCabling_01.txt");
		instance1.Execute();
		break;
	}
	default:
	{
		cout << "Wrong selection - Exiting";
		break;
	}
	}
	

}

