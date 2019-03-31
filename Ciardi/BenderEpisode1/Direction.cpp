#include "Direction.h"
#include <utility> 

std::pair<int, int> GetTupleFromDirection(Direction d) {
	switch (d) {
	case Direction::NORTH:
		return { 0,-1 };
	case Direction::SOUTH:
		return { 0,1 };
	case Direction::EAST:
		return { 1,0 };
	case Direction::WEST:
		return { -1,0 };
	}
	return { 0,0 };
}

std::string GetStringFromDirection(Direction d) {
	switch (d) {
	case Direction::NORTH:
		return "NORTH";
	case Direction::SOUTH:
		return "SOUTH";
	case Direction::EAST:
		return "EAST";
	case Direction::WEST:
		return "WEST";
	}
	return "NONE";
}
