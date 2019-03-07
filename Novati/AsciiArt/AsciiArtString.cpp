#include "stdafx.h"
#include "AsciiArtString.h"

using namespace std;

namespace AsciiArt
{
	AsciiArtString::AsciiArtString(int L, int H, string T, vector<string> INPUT_ROWS) {
		_L = L;
		_H = H;
		_T = T;
		_INPUT_ROWS = INPUT_ROWS;
		parse();
	}
	
	AsciiArtString::~AsciiArtString() {
	}

	string* split(string src, int len) {
		size_t chunks = src.length() / len;

		if (chunks == 0)
			return new string("");

		string* result = new string[chunks];

		for (int i = 0; i < chunks; i++) {
			int start = i * len;
			//int end = (i + 1) * len-1;
			string chunk = src.substr(start, len);
			result[i] = chunk;
		}
		return result;
	}

	void AsciiArtString::parse() {
		for (int index = 0; index < _H; index++) {
			string ROW = _INPUT_ROWS[index];

			string* split_rows = split(ROW, _L);

			a.setRow(split_rows[0], index);
			b.setRow(split_rows[1], index);
			c.setRow(split_rows[2], index);
			d.setRow(split_rows[3], index);
			e.setRow(split_rows[4], index);
			f.setRow(split_rows[5], index);
			g.setRow(split_rows[6], index);
			h.setRow(split_rows[7], index);
			i.setRow(split_rows[8], index);
			j.setRow(split_rows[9], index);
			k.setRow(split_rows[10], index);
			l.setRow(split_rows[11], index);
			m.setRow(split_rows[12], index);
			n.setRow(split_rows[13], index);
			o.setRow(split_rows[14], index);
			p.setRow(split_rows[15], index);
			q.setRow(split_rows[16], index);
			r.setRow(split_rows[17], index);
			s.setRow(split_rows[18], index);
			t.setRow(split_rows[19], index);
			u.setRow(split_rows[20], index);
			v.setRow(split_rows[21], index);
			w.setRow(split_rows[22], index);
			x.setRow(split_rows[23], index);
			y.setRow(split_rows[24], index);
			z.setRow(split_rows[25], index);
			qm.setRow(split_rows[26], index);
		}
	}

	void AsciiArtString::print() {
		const size_t length = _T.length();

		const char* phrase = _T.c_str();

		for (int row_index = 0; row_index < _H; row_index++) {
			string row_N = "";

			for (int index = 0; index < length; index++) {

				if (phrase[index] == 'a' || phrase[index] == 'A') {
					row_N = row_N + a.getRow(row_index);
				}
				else if (phrase[index] == 'b' || phrase[index] == 'B') {
					row_N = row_N + b.getRow(row_index);
				}
				else if (phrase[index] == 'c' || phrase[index] == 'C') {
					row_N = row_N + c.getRow(row_index);
				}
				else if (phrase[index] == 'd' || phrase[index] == 'D') {
					row_N = row_N + d.getRow(row_index);
				}
				else if (phrase[index] == 'e' || phrase[index] == 'E') {
					row_N = row_N + e.getRow(row_index);
				}
				else if (phrase[index] == 'f' || phrase[index] == 'F') {
					row_N = row_N + f.getRow(row_index);
				}
				else if (phrase[index] == 'g' || phrase[index] == 'G') {
					row_N = row_N + g.getRow(row_index);
				}
				else if (phrase[index] == 'h' || phrase[index] == 'H') {
					row_N = row_N + h.getRow(row_index);
				}
				else if (phrase[index] == 'i' || phrase[index] == 'I') {
					row_N = row_N + i.getRow(row_index);
				}
				else if (phrase[index] == 'j' || phrase[index] == 'J') {
					row_N = row_N + j.getRow(row_index);
				}
				else if (phrase[index] == 'k' || phrase[index] == 'K') {
					row_N = row_N + k.getRow(row_index);
				}
				else if (phrase[index] == 'l' || phrase[index] == 'L') {
					row_N = row_N + l.getRow(row_index);
				}
				else if (phrase[index] == 'm' || phrase[index] == 'M') {
					row_N = row_N + m.getRow(row_index);
				}
				else if (phrase[index] == 'n' || phrase[index] == 'N') {
					row_N = row_N + n.getRow(row_index);
				}
				else if (phrase[index] == 'o' || phrase[index] == 'O') {
					row_N = row_N + o.getRow(row_index);
				}
				else if (phrase[index] == 'p' || phrase[index] == 'P') {
					row_N = row_N + p.getRow(row_index);
				}
				else if (phrase[index] == 'q' || phrase[index] == 'Q') {
					row_N = row_N + q.getRow(row_index);
				}
				else if (phrase[index] == 'r' || phrase[index] == 'R') {
					row_N = row_N + r.getRow(row_index);
				}
				else if (phrase[index] == 's' || phrase[index] == 'S') {
					row_N = row_N + s.getRow(row_index);
				}
				else if (phrase[index] == 't' || phrase[index] == 'T') {
					row_N = row_N + t.getRow(row_index);
				}
				else if (phrase[index] == 'u' || phrase[index] == 'U') {
					row_N = row_N + u.getRow(row_index);
				}
				else if (phrase[index] == 'v' || phrase[index] == 'V') {
					row_N = row_N + v.getRow(row_index);
				}
				else if (phrase[index] == 'w' || phrase[index] == 'W') {
					row_N = row_N + w.getRow(row_index);
				}
				else if (phrase[index] == 'x' || phrase[index] == 'X') {
					row_N = row_N + x.getRow(row_index);
				}
				else if (phrase[index] == 'y' || phrase[index] == 'Y') {
					row_N = row_N + y.getRow(row_index);
				}
				else if (phrase[index] == 'z' || phrase[index] == 'Z') {
					row_N = row_N + z.getRow(row_index);
				}
				else {
					row_N = row_N + qm.getRow(row_index);
				}

			
			}
			cout << row_N << "\r\n";
			//delete phrase;
		}
	}
}