#pragma once

#include <string>

enum class Direction { NORTH, EAST, SOUTH, WEST};

std::pair<int, int> GetTupleFromDirection(Direction d);
std::string GetStringFromDirection(Direction d);
