#include "pch.h"
#include "GameOfLifeTest.h"
#include <fstream>

using namespace GameOfLife;
using namespace std;

namespace CodinGame {

	GameOfLifeTest::GameOfLifeTest() {

	}

	GameOfLifeTest::~GameOfLifeTest() {
		delete gol;
	}

	GameOfLifeTest::GameOfLifeTest(const char* INPUT_FILENAME) {
		Init(string(INPUT_FILENAME));
	}

	void GameOfLifeTest::Init(const string INPUT_FILENAME) {
		int L, W;

		_INPUT_FILENAME = INPUT_FILENAME;

		vector<string> INPUT_ROWS;

		ifstream input(_INPUT_FILENAME);

		//auto cinbuf = cin.rdbuf(input.rdbuf());

		input >> L;
		input >> W;

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

		gol = new  GameOfLifeGM(L, W, INPUT_ROWS);
	}

	GameOfLifeTest::GameOfLifeTest(const string INPUT_FILENAME) {
		Init(INPUT_FILENAME);
	}

	void GameOfLifeTest::Execute() {
		cout << "Execute " << _INPUT_FILENAME << "\n";
		gol->computeNext();
	}
}