#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

namespace HiddenWord
{
	class HiddenWordStriker
	{
	public:

		enum Direction
		{
			horizontalL2R,
			horizontalR2L,
			verticalU2D,
			verticalD2U,
			diagonalL2RU2D,
			diagonalL2RD2U,
			diagonalR2LU2D,
			diagonalR2LD2U
		};

		struct DirectionOffset
		{
			Direction direction;
			int x;
			int y;
		};

		static const int _directions = 8;

		const DirectionOffset _dirOffsets[_directions] = { {Direction::diagonalR2LD2U, -1, -1},
														   {Direction::verticalD2U, -1, 0},
												           {Direction::diagonalL2RD2U, -1, 1},
												           {Direction::horizontalR2L, 0, -1},
												           {Direction::horizontalL2R, 0, 1},
												           {Direction::diagonalR2LU2D, 1, -1},
												           {Direction::verticalU2D, 1, 0},
												           {Direction::diagonalL2RU2D, 1, 1} };

		HiddenWordStriker(const std::string& filePath);
		void Execute();

		bool searchInAllDirections(int atRow, 
								   int atCol, 
								   const std::string& word, 
								   DirectionOffset& foundAlong) const;
	private:
		std::vector<std::string> _keywords;
		char** _charMatrix;
		bool** _flagMatrix;

		int _rows;
		int _cols;
	};
}