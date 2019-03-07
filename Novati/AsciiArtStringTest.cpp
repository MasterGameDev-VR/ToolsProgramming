#include "pch.h"
#include "AsciiArtStringTest.h"

using namespace AsciiArt;
using namespace std;

namespace CodinGame {

	    AsciiArtStringTest::AsciiArtStringTest() {
		}

		AsciiArtStringTest::~AsciiArtStringTest() {
			delete str;
		}

		AsciiArtStringTest::AsciiArtStringTest(const char* INPUT_FILENAME) {
			Init(string(INPUT_FILENAME));
		}

		void AsciiArtStringTest::Init(const string INPUT_FILENAME) {
			int L, H;

			_INPUT_FILENAME = INPUT_FILENAME;

			string T;

			vector<string> INPUT_ROWS;

			ifstream input(_INPUT_FILENAME);

			input >> L;
			input >> H;
			input >> T;

			cout << "H:" << H << "\n";
			cout << "H:" << L << "\n";
			cout << "T:" << T << "\n" << "\n";

			for (int i = 0; i < H; i++) {
				string ROW;
				input >> ROW;
				INPUT_ROWS.push_back(ROW);
			}

			for (vector<string>::const_iterator i = INPUT_ROWS.begin(); i != INPUT_ROWS.end(); ++i) {
				cout << *i << "\n";
			}

			str = new  AsciiArtString(L, H, T, INPUT_ROWS);
		}

		AsciiArtStringTest::AsciiArtStringTest( const string INPUT_FILENAME ) {
			Init(INPUT_FILENAME);
		}

		void AsciiArtStringTest::Execute() {
			cout << "Execute " << _INPUT_FILENAME << "\n";

			str->print();
		}
}