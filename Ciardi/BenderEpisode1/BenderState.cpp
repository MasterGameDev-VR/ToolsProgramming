#include "BenderState.h"

void BenderState::SetX(int x) {
	this->x = x;
}

void BenderState::SetY(int y) {
	this->y = y;
}

int BenderState::GetX() const {
	return x;
}

int BenderState::GetY() const {
	return y;
}

void BenderState::SetDirection(Direction d) {
	direction = d;
}

Direction BenderState::GetDirection() const {
	return direction;
}

void BenderState::Invert() {
	inverted = !inverted;
}

bool BenderState::IsInverted() const {
	return inverted;
}

void BenderState::SetBeerMode(bool b) {
	beerMode = b;
}

bool BenderState::GetBeerMode() const {
	return beerMode;
}

bool BenderState::operator==(const BenderState & rhs) const {
	if (this->x != rhs.x || this->y != rhs.y || this->inverted != rhs.inverted || this->beerMode != rhs.beerMode || this->direction != rhs.direction) {
		return false;
	}
	return true;
}
