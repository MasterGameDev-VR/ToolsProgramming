#include "stdafx.h"
#include "Letter.h"

namespace AsciiArt {

	Letter::Letter() {
	}

	Letter::~Letter() {
	}

	void Letter::setRow(std::string row, int row_num) {
		_rows.insert(_rows.begin() + row_num, row);
	}

	std::string Letter::getRow(int num) {
		if (num >= _rows.size())
			return NULL;

		return _rows[num];
	}

	std::string Letter::toString() {
		int height = Letter::getHeight();

		std::string ret = "";

		for (int row = 0; row < height; row++) {
			ret.append(getRow(row));
			ret.append("\n");
		}

		return ret;
	}
}