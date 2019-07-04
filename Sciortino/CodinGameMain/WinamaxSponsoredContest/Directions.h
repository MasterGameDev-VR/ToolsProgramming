#pragma once

#define UP '^'
#define DOWN 'v'
#define RIGHT '>'
#define LEFT '<'
#define NONE ' '

#define HOLE 'H'
#define HAZARD 'X'
#define EMPTY '.'

enum class Directions : char
{
	up = UP,
	down = DOWN,
	right = RIGHT,
	left = LEFT,
	none = NONE
};