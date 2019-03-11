// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "..\BenderEpisode1\BenderEpisode1.h"
#include "..\TheTravellingSalesmanProblem\TheTravellingSalesmanProblem.h"
#include "..\ASCIIArt\ASCIIArt.h"

using std::cin;
using std::cout;
using std::endl;

void BenderProblem();
void SalesmanProblem();
void ASCIIArtProblem();
int SelectCase(int maxCase);

int main() {
		cout << "Federico Ciardi - Tools programming" << endl;
		cout << "1) Bender - Episode 1" << endl;
		cout << "2) The Travelling Salesman Problem" << endl;
		cout << "3) ASCII Art" << endl;
		cout << "0) Exit" << endl;

		cout << endl;
		cout << "Inserire ID: ";

		int choice;
		cin >> choice;

		switch (choice) {
		case 0:
			return 0;
		case 1:
			BenderProblem();
			break;
		case 2:
			SalesmanProblem();
			break;
		case 3:
			ASCIIArtProblem();
			break;
		default:
			cout << "ID inserito non esistente!" << endl;
		}

		system("PAUSE");
}


void BenderProblem() {
	int caseNumber = SelectCase(12);
	BenderEpisode1 benderEpisode1{ "..\\BenderEpisode1\\Tests\\BenderEpisode1-" + std::to_string(caseNumber) + ".txt" };
	benderEpisode1.Execute();
}

void SalesmanProblem() {
	int caseNumber = SelectCase(4);
	TheTravellingSalesmanProblem salesmanProblem{ "..\\TheTravellingSalesmanProblem\\Tests\\TheTravellingSalesmanProblem-" + std::to_string(caseNumber) + ".txt" };
	salesmanProblem.Execute();
}

void ASCIIArtProblem() {
	int caseNumber = SelectCase(5);
	ASCIIArt asciiArt{ "..\\ASCIIArt\\Tests\\ASCIIArt-" + std::to_string(caseNumber) + ".txt" };
	asciiArt.Execute();
}

int SelectCase(int maxCase) {
	int choice = -1;
	while (true) {
		cout << "Inserire ID testcase (da 1 a " + std::to_string(maxCase) + "): ";
		cin >> choice;
		if (choice >= 1 || choice <= maxCase) {
			return choice;
		}
	}
}

