// ChuckNorris.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ChuckNorris.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ChuckNorris::ChuckNorris(std::string fileName) : m_fileName(fileName) {

}

void ChuckNorris::Execute() {
	std::ifstream in(m_fileName);
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	string MESSAGE;
	string answer = "";
	short state = -1;
	getline(cin, MESSAGE);

	for (size_t i = 0; i < MESSAGE.size(); i++) {
		for (short j = 0; j < 7; j++) {
			if (MESSAGE[i] & 1 << (6 - j)) {
				if (state != 1) {
					state = 1;
					answer.append(" 0 ");
				}
			}
			else {
				if (state != 0) {
					state = 0;
					answer.append(" 00 ");
				}
			}
			answer.append("0");
		}
	}

	answer.erase(0, 1);

	cout << answer << endl;
}