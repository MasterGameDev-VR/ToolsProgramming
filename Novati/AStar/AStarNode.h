#pragma once
class AStarNode {
private:

public:
	int x;
	int y;

	int g;
	int h;

	bool operator == (const AStarNode&);
};