#include "stdafx.h"
#include "MapObject.h"


MapObject::MapObject(int x_init, int y_init, bool isEmpty_init = true) : x(x_init), y(y_init), isEmpty(isEmpty_init)
{
}


MapObject::~MapObject()
{
}

int MapObject::GetCol() {
	return x;
}
int MapObject::GetRow() {
	return y;
}
bool MapObject::GetIsEmpty() {
	return isEmpty;
}