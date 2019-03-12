// GameOfLife.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "GameOfLifeGM.h"

namespace GameOfLife {
	GameOfLifeGM::GameOfLifeGM(int W, int H, vector<string> INPUT_ROWS) {
		width = W;
		height = H;

		current = new bool[width*height];
		next_state = new bool[width*height];

		for (int y = 0; y < height; y++) {
			string line = INPUT_ROWS[y];

			const char *c_str = line.c_str();
			for (int x = 0; x < width; x++)
				current[y*width + x] = c_str[x] - 48;
			// cerr<<line<<"\n";
		}
	}


	GameOfLifeGM::~GameOfLifeGM() {
		delete[] next_state;
		delete[] current;
	}

	int GameOfLifeGM::howManyAliveAround(int x, int y) {
		int counter = 0;
		for (int yy = y - 1; yy <= y + 1; yy++)
			for (int xx = x - 1; xx <= x + 1; xx++)
				if (xx >= 0 &&
					yy >= 0 &&
					xx < width &&
					yy < height &&
					(xx != x || yy != y)
					&& *(current + (yy*width + xx)))
					counter++;

		return counter;
	}

	void GameOfLifeGM::computeNext() {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int alive = howManyAliveAround(x, y);
				//cerr << alive;
				*(next_state + (y*width + x)) = (*(current + (y*width + x)) && alive == 2) || alive == 3;
			}
			//    cerr<<"\n";
		}
	}
}