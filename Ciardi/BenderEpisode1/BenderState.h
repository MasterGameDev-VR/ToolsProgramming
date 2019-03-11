#pragma once
#include "Direction.h"

class BenderState {
public:
	BenderState() {};
	void SetX(int x);
	int GetX() const;
	void SetY(int y);
	int GetY() const;
	void SetDirection(Direction d);
	Direction GetDirection() const;
	void Invert();
	bool IsInverted() const;
	void SetBeerMode(bool b);
	bool GetBeerMode() const;
	bool operator==(const BenderState& rhs) const;
private:
	int x = 0;
	int y = 0;
	bool inverted = false;
	bool beerMode = false;
	Direction direction = Direction::SOUTH;
};