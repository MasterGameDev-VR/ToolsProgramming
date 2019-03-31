// ASCIIArt.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ASCIIArt.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::streambuf;
using std::string;

ASCIIArt::ASCIIArt(std::string fileName) {
	ifstream inputFileStream{ fileName };
	streambuf* inputBuffer = cin.rdbuf(inputFileStream.rdbuf());

	cin >> L; cin.ignore();
	cin >> H; cin.ignore();

	std::getline(cin, T);
	std::transform(T.begin(), T.end(), T.begin(), ::toupper);
	string ROW;
	for (size_t i = 0; i < H; i++) {
		getline(cin, ROW);
		ROWS.push_back(ROW);
		finalRows.push_back("");
	}
}

void ASCIIArt::Execute() {
	for (size_t i = 0; i < T.size(); i++) {
		int number = T[i] - 'A';
		for (size_t nr = 0; nr < H; nr++) {
			if (number >= 0 && number < 26) {
				finalRows[nr] += ROWS[nr].substr(number*L, L);
			}
			else {
				finalRows[nr] += ROWS[nr].substr(26 * L, L);
			}
		}

	}
	for (size_t i = 0; i < H; i++) {
		cout << finalRows[i] << endl;
	}
}
