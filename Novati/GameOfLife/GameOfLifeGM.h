#pragma once
#include <vector>
#include <string>

using namespace std;

namespace GameOfLife {
	class GameOfLifeGM {
	private:

		int width;
		int height;

		bool *current;
		bool *next_state;

	public:
		GameOfLifeGM(int W, int H, vector<string> INPUT_ROWS);
		virtual ~GameOfLifeGM();
		int howManyAliveAround(int x, int y);
		void computeNext();
	};
}