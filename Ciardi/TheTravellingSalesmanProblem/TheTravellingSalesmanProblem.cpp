// TheTravellingSalesmanProblem.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "TheTravellingSalesmanProblem.h"
#include <iostream>
#include <fstream>
#include <limits>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::streambuf;

TheTravellingSalesmanProblem::TheTravellingSalesmanProblem(std::string fileName) {
	ifstream inputFileStream{ fileName };
	streambuf* inputBuffer = cin.rdbuf(inputFileStream.rdbuf());

	int N;
	cin >> N; cin.ignore();

	for (size_t i = 0; i < N; i++) {
		int X;
		int Y;
		cin >> X >> Y; cin.ignore();
		cities.push_back(std::make_pair(X, Y));
	}
}

void TheTravellingSalesmanProblem::Execute() {
	std::pair<int, int> original = cities[0];
	double totalDistance = 0;

	for (int position = 0; cities.size() > 1;) {
		int dest = FindNear(position);
		totalDistance += sqrt(pow(cities[position].first - cities[dest].first, 2) +
			pow(cities[position].second - cities[dest].second, 2));
		cities.erase(cities.begin() + position);
		if (position < dest) {
			dest--;
		}
		position = dest;
	}
	totalDistance += sqrt(pow(cities[0].first - original.first, 2) + pow(cities[0].second - original.second, 2));

	cout << round(totalDistance) << endl;
}

int TheTravellingSalesmanProblem::FindNear(int position) {
	double mind = (std::numeric_limits<double>::max)();
	int dest = -1;
	for (int i = 0; i < cities.size(); i++) {
		if (i != position) {
			double distance = sqrt(pow(cities[position].first - cities[i].first, 2) + pow(cities[position].second - cities[i].second, 2));
			if (distance < mind) {
				mind = distance;
				dest = i;
			}
		}
	}
	return dest;
}
