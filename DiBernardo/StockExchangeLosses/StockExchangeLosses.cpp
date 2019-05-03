
#include "stdafx.h"
#include "StockExchangeLosses.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <fstream>

using namespace std;

StockExchangeLosses::StockExchangeLosses(std::string fileName) : m_fileName(fileName) {

}

void StockExchangeLosses::Execute() {
	std::ifstream in(m_fileName);
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	int n;
	cin >> n; cin.ignore();
	string vs;
	getline(cin, vs);

	vector<int> values;
	stringstream ss(vs);
	for (int i = 0; i < n; ++i) {
		string temp;
		ss >> temp;
		values.push_back(stoi(temp));
	}

	int loss = 0;
	int maxSeen = values[0];
	int minSeen = values[0];
	for (int i = 1; i < n; ++i) {
		if (values[i] > maxSeen) {
			maxSeen = values[i];
		}
		else {
			minSeen = values[i];
			if ((maxSeen - minSeen) > loss) {
				loss = maxSeen - minSeen;
			}
		}
	}

	cout << -loss << endl;
}
