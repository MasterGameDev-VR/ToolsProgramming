#include "stdafx.h"
#include "BenderStatus.h"
#include <utility>


BenderStatus::BenderStatus(int x, int y, bool i, bool b, std::string dir, int distruct)
{
	BenderX = x;
	BenderY = y;
	inverted = i;
	beerMode = b;
	direction = dir;
	distruction_count = distruct;
}

bool BenderStatus::Equals(BenderStatus other)
{
	if (
		BenderX == other.BenderX &&
		BenderY == other.BenderY &&
		inverted == other.inverted &&
		beerMode == other.beerMode &&
		direction == other.direction &&
		distruction_count == other.distruction_count)
		return true;
	else
		return false;
}

std::string BenderStatus::ToString()
{
	return std::to_string(BenderX) + " " + std::to_string(BenderY) + " " + std::to_string(inverted) + " " + std::to_string(beerMode) + " " + direction + " " + std::to_string(distruction_count);
}



std::pair<int, int> BenderStatus::GetDirInt(std::string direction)
{
	if (direction == "NORTH")
		return { 0,-1 };
	if (direction == "SOUTH")
		return { 0,1 };
	if (direction == "EAST")
		return { 1,0 };
	if (direction == "WEST")
		return { -1,0 };

	return { 0,0 };
}

void BenderStatus::ChangeDir(std::vector<std::vector<char>>& map)
{

	if (inverted) {
		std::pair<int, int> dirIncrease = GetDirInt("WEST");
		char mapPos = map[BenderY + dirIncrease.second][BenderX + dirIncrease.first];
		if (mapPos == '#' || (mapPos == 'X' && !beerMode))
		{
			std::pair<int, int> dirIncrease = GetDirInt("NORTH");
			char mapPos = map[BenderY + dirIncrease.second][BenderX + dirIncrease.first];
			if (mapPos == '#' || (mapPos == 'X' && !beerMode))
			{
				std::pair<int, int> dirIncrease = GetDirInt("EAST");
				char mapPos = map[BenderY + dirIncrease.second][BenderX + dirIncrease.first];
				if (mapPos == '#' || (mapPos == 'X' && !beerMode))
				{
					direction = "SOUTH";
				}
				else
				{
					direction = "EAST";
				}
			}
			else
			{
				direction = "NORTH";
			}
		}
		else
		{
			direction = "WEST";
		}
	}
	else {
		std::pair<int, int> dirIncrease = GetDirInt("SOUTH");
		char mapPos = map[BenderY + dirIncrease.second][BenderX + dirIncrease.first];
		if (mapPos == '#' || (mapPos == 'X' && !beerMode))
		{
			std::pair<int, int> dirIncrease = GetDirInt("EAST");
			char mapPos = map[BenderY + dirIncrease.second][BenderX + dirIncrease.first];
			if (mapPos == '#' || (mapPos == 'X' && !beerMode))
			{
				std::pair<int, int> dirIncrease = GetDirInt("NORTH");
				char mapPos = map[BenderY + dirIncrease.second][BenderX + dirIncrease.first];
				if (mapPos == '#' || (mapPos == 'X' && !beerMode))
				{
					direction = "WEST";
				}
				else
				{
					direction = "NORTH";
				}
			}
			else
			{
				direction = "EAST";
			}
		}
		else
		{
			direction = "SOUTH";
		}

	}
}

