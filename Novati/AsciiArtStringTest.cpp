#include "pch.h"
#include "AsciiArt/AsciiArtString.cpp"

using namespace AsciiArt;

namespace CodinGame {

	class AsciiArtStringTest {
	protected:
		AsciiArtString *str;
		std::string& _INPUT_FILENAME;
	public:
		AsciiArtStringTest() {
			
		}

		~AsciiArtStringTest() {
			delete str;
		}

		AsciiArtStringTest( const std::string &INPUT_FILENAME ) {
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

		void Execute() {
			cout << "Execute " << _INPUT_FILENAME << "\n";

			str->print();
		}
	};
}