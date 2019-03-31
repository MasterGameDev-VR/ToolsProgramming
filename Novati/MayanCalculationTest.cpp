#include "pch.h"
#include <fstream>
#include "MayanCalculationTest.h"

using namespace std;

namespace CodinGame {

	MayanCalculationTest::MayanCalculationTest() {

	}

	MayanCalculationTest::~MayanCalculationTest() {
		delete str;
	}

	MayanCalculationTest::MayanCalculationTest(const char* INPUT_FILENAME) {
		_INPUT_FILENAME = INPUT_FILENAME;
		Init(string(_INPUT_FILENAME));
	}

	void MayanCalculationTest::Init(const string INPUT_FILENAME) {
		char* chr = const_cast<char*>(INPUT_FILENAME.c_str());
		str = new  MayanCalculation(chr);
	}

	MayanCalculationTest::MayanCalculationTest(const string INPUT_FILENAME) {
		Init(INPUT_FILENAME);
	}

	void MayanCalculationTest::Execute() {
		cout << "Execute \n";

		str->Execute();
	}
}