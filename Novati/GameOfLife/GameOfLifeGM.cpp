// GameOfLife.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "GameOfLifeGM.h"

namespace GameOfLife {


	GameOfLifeGM::GameOfLifeGM(const string INPUT_FILENAME) {
		int L, W;
		wchar_t  path_buffer[255];
		GetModuleFileName(NULL, path_buffer, 255);
		wstring ws(path_buffer);
		// your new String
		string str(ws.begin(), ws.end());
		string::size_type pos = string(str).find_last_of("\\/");
		string path =  string(str).substr(0, pos);

		string _INPUT_FILENAME = path +"\\"+ INPUT_FILENAME;

		vector<string> INPUT_ROWS;

		ifstream input(_INPUT_FILENAME);

		//auto cinbuf = cin.rdbuf(input.rdbuf());

		input >> L;
		input >> W;
		cout << "file name:" << path << INPUT_FILENAME << "\n";
		cout << "L:" << L << "\n";
		cout << "W:" << W << "\n";

		for (int i = 0; i <= W; i++) {
			string ROW;
			getline(input, ROW);
			if (ROW == "")
				continue;

			INPUT_ROWS.push_back(ROW);
		}

		for (vector<string>::const_iterator i = INPUT_ROWS.begin(); i != INPUT_ROWS.end(); ++i) {
			cout << *i << "\n";
		}

		InitGameOfLifeGM(L, W, INPUT_ROWS);
	}

	GameOfLifeGM::GameOfLifeGM(int W, int H, vector<string> INPUT_ROWS) {
		InitGameOfLifeGM(W, H, INPUT_ROWS);
	}

	void GameOfLifeGM::InitGameOfLifeGM(int W, int H, vector<string> INPUT_ROWS) {
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