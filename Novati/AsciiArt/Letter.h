#pragma once
#include "stdafx.h"
#include "Draw.h"

namespace AsciiArt {

	class Letter : Draw {
	protected:
		std::vector<std::string> _rows;

	public:
		Letter();
		virtual ~Letter();

		virtual std::string getRow(int num);

		virtual void setRow(std::string row, int row_num);

		virtual std::string toString();
	};
}