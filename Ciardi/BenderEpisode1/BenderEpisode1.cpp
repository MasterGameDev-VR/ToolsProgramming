#include "stdafx.h"
#include "BenderEpisode1.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::streambuf;

BenderEpisode1::BenderEpisode1(std::string fileName) {
	ifstream inputFileStream{ fileName };
	streambuf* inputBuffer = cin.rdbuf(inputFileStream.rdbuf());

	int L, C;

	cin >> L; cin.ignore();
	cin >> C; cin.ignore();

	for (int i = 0; i < L; i++) {
		std::string row;
		std::getline(std::cin, row);

		map.push_back({});
		for (int j = 0; j < C; ++j) {
			map.back().push_back(row[j]);

			if (row[j] == '@') {
				currentState.SetX(j);
				currentState.SetY(i);
			} else if (row[j] == 'T') {
				teleporters.push_back({ j, i });
			}
		}
	}
}

void BenderEpisode1::Execute() {
	while (map[currentState.GetY()][currentState.GetX()] != '$') {
		if (IsInLoop()) {
			cout << "LOOP" << endl;
			return;
		}

		visited[{currentState.GetX(), currentState.GetY()}].push_back(currentState);

		switch (map[currentState.GetY()][currentState.GetX()]) {
		case 'N':
			currentState.SetDirection(Direction::NORTH);
			break;
		case 'E':
			currentState.SetDirection(Direction::EAST);
			break;
		case 'S':
			currentState.SetDirection(Direction::SOUTH);
			break;
		case 'W':
			currentState.SetDirection(Direction::WEST);
			break;
		case 'I':
			currentState.Invert();
			break;
		case 'B':
			currentState.SetBeerMode(!currentState.GetBeerMode());
			break;
		case 'T':
			if ((currentState.GetX() == teleporters[0].first)) {
				currentState.SetX(teleporters[1].first);
				currentState.SetY(teleporters[1].second);
			} else {
				currentState.SetX(teleporters[0].first);
				currentState.SetY(teleporters[0].second);
			}
			break;
		};

		Move();

		cout << GetStringFromDirection(currentState.GetDirection()) << endl;
	}
}

void BenderEpisode1::Move() {
	std::pair<int, int> add = GetTupleFromDirection(currentState.GetDirection());

	if (map[currentState.GetY() + add.second][currentState.GetX() + add.first] == 'X') {
		if (currentState.GetBeerMode()) {
			map[currentState.GetY() + add.second][currentState.GetX() + add.first] = ' ';
			visited.clear();
		} else {
			Obstacle();
			return;
		}
	} else if (map[currentState.GetY() + add.second][currentState.GetX() + add.first] == '#') {
		Obstacle();
		return;
	}
		
	currentState.SetX(currentState.GetX() + add.first);
	currentState.SetY(currentState.GetY() + add.second);
}

void BenderEpisode1::Obstacle() {
	std::vector<Direction> priority = { Direction::SOUTH, Direction::EAST, Direction::NORTH, Direction::WEST };

	if (currentState.IsInverted())
		std::reverse(priority.begin(), priority.end());

	for (Direction dir : priority) {
		std::pair<int, int> add = GetTupleFromDirection(dir);
		if ((map[currentState.GetY() + add.second][currentState.GetX() + add.first] != 'X') && (map[currentState.GetY() + add.second][currentState.GetX() + add.first] != '#')) {
			currentState.SetX(currentState.GetX() + add.first);
			currentState.SetY(currentState.GetY() + add.second);
			currentState.SetDirection(dir);
			return;
		}
	}
}

bool BenderEpisode1::IsInLoop() {
	std::pair<int, int> pos = { currentState.GetX(), currentState.GetY() };
	if (visited.find(pos) != visited.end()) {
		if (std::find(visited[pos].begin(), visited[pos].end(), currentState) != visited[pos].end()) {
			return true;
		}
	}
	return false;
}
