#include "stdafx.h"
#include "BenderEp1.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::streambuf;

BenderEp1::BenderEp1(std::string filePath)
{
	file = filePath;

	ifstream inputFileStream{ file };
	streambuf* inputBuffer = cin.rdbuf(inputFileStream.rdbuf());

	int L, C;

	cin >> L; cin.ignore();
	cin >> C; cin.ignore();

	for (int i = 0; i < L; i++)
	{
		std::string row;
		std::getline(std::cin, row);

		map.push_back({});
		for (int j = 0; j < C; ++j) {
			map.back().push_back(row[j]);

			if (row[j] == '@') {
				currentStatus.BenderX = j;

				currentStatus.BenderY = i;
			}
			else if (row[j] == 'T') {
				teleporters.push_back({ j, i });
			}
		}
	}

}

void BenderEp1::Execute()
{
	while (alive && !isLoop)
	{
		for (int i = 0; i < OldStatuses.size() && !isLoop; i++) {
			if (currentStatus.Equals(OldStatuses[i]))
				isLoop = true;
		}
		if (isLoop)
		{
			cout << "LOOP" << endl;
			continue;
		}
		OldStatuses.push_back(currentStatus);
		std::pair<int, int> dirIncrease = BenderStatus::GetDirInt(currentStatus.direction);
		char mapPos = map[currentStatus.BenderY + dirIncrease.second][currentStatus.BenderX + dirIncrease.first];

		if (mapPos == ' ')
		{
			currentStatus.BenderY += dirIncrease.second;
			currentStatus.BenderX += dirIncrease.first;
			moves.push_back(currentStatus.direction);
			continue;
		}
		if (mapPos == 'T')
		{
			currentStatus.BenderY += dirIncrease.second;
			currentStatus.BenderX += dirIncrease.first;
			moves.push_back(currentStatus.direction);
			if (currentStatus.BenderX == teleporters[0].first && currentStatus.BenderY == teleporters[0].second)
			{
				currentStatus.BenderX = teleporters[1].first;
				currentStatus.BenderY = teleporters[1].second;
			}
			else
			{
				currentStatus.BenderX = teleporters[0].first;
				currentStatus.BenderY = teleporters[0].second;
			}
			continue;
		}
		if (mapPos == 'B')
		{
			currentStatus.beerMode = !currentStatus.beerMode;
			currentStatus.BenderY += dirIncrease.second;
			currentStatus.BenderX += dirIncrease.first;
			moves.push_back(currentStatus.direction);
			continue;
		}
		if (mapPos == 'I')
		{
			currentStatus.inverted = !currentStatus.inverted;
			currentStatus.BenderY += dirIncrease.second;
			currentStatus.BenderX += dirIncrease.first;
			moves.push_back(currentStatus.direction);
			continue;
		}
		if (mapPos == 'S')
		{
			currentStatus.BenderY += dirIncrease.second;
			currentStatus.BenderX += dirIncrease.first;
			moves.push_back(currentStatus.direction);
			currentStatus.direction = "SOUTH";
			continue;
		}
		if (mapPos == 'E')
		{
			currentStatus.BenderY += dirIncrease.second;
			currentStatus.BenderX += dirIncrease.first;
			moves.push_back(currentStatus.direction);
			currentStatus.direction = "EAST";
			continue;
		}
		if (mapPos == 'N')
		{
			currentStatus.BenderY += dirIncrease.second;
			currentStatus.BenderX += dirIncrease.first;
			moves.push_back(currentStatus.direction);
			currentStatus.direction = "NORTH";
			continue;
		}
		if (mapPos == 'W')
		{
			currentStatus.BenderY += dirIncrease.second;
			currentStatus.BenderX += dirIncrease.first;
			moves.push_back(currentStatus.direction);
			currentStatus.direction = "WEST";
			continue;
		}
		if (mapPos == 'X' && currentStatus.beerMode)
		{
			map[currentStatus.BenderY + dirIncrease.second][currentStatus.BenderX + dirIncrease.first] = ' ';
			currentStatus.distruction_count++;
			continue;
		}
		if (mapPos == '#' || mapPos == 'X' && !currentStatus.beerMode)
		{
			currentStatus.ChangeDir(map);
			continue;
		}
		if (mapPos == '$')
		{
			moves.push_back(currentStatus.direction);
			alive = false;
		}
	}
	if (!alive) 
	{
		for (int i = 0; i < moves.size(); i++) {
			cout << moves[i] << endl;
		}
	}
}


