// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "..\NumberOfLettersInANumber\NumberOfLettersInANumber.h"
#include "..\NetworkCabling\NetworkCabling.h"
#include "..\..\Zamprogno\MayanCalculation\MayanCalculation.cpp"


using namespace std;

int main()
{
	int choice;
	cout << "Riccardo Caldana - Master CGD 2018/2019 - Tools Programming Exam\n";
	cout << "Insert 1 to select NumberOfLetterInANumber\nInsert 2 to select NetworkCabling\nInsert 3 to select MayanCalculation\n";
	cin >> choice; cin.ignore();
	string path1 = "..\\Test\\NumberOfLettersInANumber\\";
	string path2 = "..\\Test\\NetworkCabling\\";
	string path3 = "..\\Test\\MayanCalculation\\";
	string testPath = "";
	string ext = ".txt";
	int numTest1 = 7;
	int numTest2 = 9;
	int numTest3 = 12;
	switch (choice) 
	{
	case 1:
	{
		int test1 = 1;
		while (test1 <= numTest1)
		{
			testPath = "..\\Test\\NumberOfLettersInANumber\\NumberOfLettersInANumber_0" + to_string(test1) + ext;
			NumberOfLettersInANumberNS::NumberOfLettersInANumber instance(testPath);
			cout << "Output Test " << test1 << ": \n";
			instance.Execute();
			test1++;
		}
		break;
	}
	case 2:
	{
		int test2 = 1;
		while (test2 <= numTest2)
		{
			testPath = "..\\Test\\NetworkCabling\\NetworkCabling_0" + to_string(test2) + ext;
			NetworkCablingNS::NetworkCabling instance1(testPath);
			cout << "Output Test " << test2 << ": \n";
			instance1.Execute();
			test2++;
		}
		break;
	}
	case 3:
	{
		int test3 = 1;
		while (test3 <= numTest3)
		{
			testPath = "..\\Test\\MayanCalculation\\MayanCalculation_0" + to_string(test3) + ext;
			MayanCalculation instance3(testPath);
			cout << "Output Test " << test3 << ": \n";
			instance3.Execute();
			test3++;
		}
		break;
	}
	default:
	{
		cout << "Wrong selection - Exiting";
		break;
	}
	}
	

}

