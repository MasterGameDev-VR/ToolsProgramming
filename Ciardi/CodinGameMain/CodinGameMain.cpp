// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "..\BenderEpisode1\BenderEpisode1.h"

using std::cin;
using std::cout;
using std::endl;

void BenderProblem();

int main() {
		cout << "Federico Ciardi - Tools programming" << endl;
		cout << "1) Bender - Episode 1" << endl;
		cout << "2)" << endl;
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
			break;
		default:
			cout << "ID inserito non esistente!" << endl;
		}

		system("PAUSE");
}


void BenderProblem() {
	for (int caseNumber = 1; caseNumber <= 12; caseNumber++) {
		BenderEpisode1 benderEpisode1{ "..\\BenderEpisode1\\Tests\\BenderEpisode1-" + std::to_string(caseNumber) + ".txt" };
		benderEpisode1.Execute();
	}
}

