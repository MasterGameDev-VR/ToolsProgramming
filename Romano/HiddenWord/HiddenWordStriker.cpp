#include "stdafx.h"
#include "HiddenWordStriker.h"
#include <stdexcept>


namespace HiddenWord
{
	HiddenWordStriker::HiddenWordStriker(const std::string & filePath)
	{
		std::ifstream input(filePath);
		auto cinbuf = std::cin.rdbuf(input.rdbuf());

		int n;
		std::cin >> n; std::cin.ignore();

		for (int i = 0; i < n; i++) 
		{
			std::string aword;
			std::cin >> aword; std::cin.ignore();
			_keywords.push_back(aword);
		}

		std::cin >> _rows >> _cols; std::cin.ignore();

		try
		{
			_charMatrix = new char*[_rows];
			_flagMatrix = new bool*[_rows];

			for (int i = 0; i < _rows; i++)
			{
				_charMatrix[i] = new char[_cols];
				_flagMatrix[i] = new bool[_cols];

				for (int j = 0; j < _cols; j++)
				{
					std::cin.get(_charMatrix[i][j]);
					_flagMatrix[i][j] = true;
				}

				std::cin.ignore();
			}

		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "Matrix allocation has failed: " << e.what() << std::endl;
			std::exit(1);
		}
	}

	void HiddenWordStriker::Execute()
	{
		for (const std::string& keyword : _keywords)
		{
			// Ogni cella della matrice viene presa come punto di partenza per la ricerca
			for (int row = 0; row < _rows; row++)
			{
				for (int col = 0; col < _cols; col++)
				{
					DirectionOffset foundAlong;
					if (searchInAllDirections(row, col, keyword, foundAlong))
					{
						int r = row;
						int c = col;

						// Strike-through della parola
						for (int i = 0; i < keyword.length(); i++)
						{
							_flagMatrix[r][c] = false;
							r += foundAlong.x;
							c += foundAlong.y;
						}

						break;
					}
				}
			}
		}

		std::cout << "Risultato:" << std::endl;

		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _cols; j++)
			{
				if (_flagMatrix[i][j])
					std::cout << _charMatrix[i][j];
			}
		}

		std::cout << std::endl;
	}

	// Questo metodo ricerca una parola a partire da una data cella in tutte e 8 le direzioni possibili
	bool HiddenWordStriker::searchInAllDirections(int atRow, 
												  int atCol,	
												  const std::string& word,
												  HiddenWordStriker::DirectionOffset& foundAlong) const
	{

		// Inutile procedere oltre se il primo carattere della keyword non è uguale a quello
		// del punto di partenza
		if (_charMatrix[atRow][atCol] != word[0])
		{
			return false;
		}

		int wordLength = word.length();

		// Ricerca in tutte le direzioni a partire da (atRow, atCol)
		for (int dir = 0; dir < 8; dir++)
		{
			int k, r, c;
			
			r = atRow + _dirOffsets[dir].x;
			c = atCol + _dirOffsets[dir].y;

			// Primo carattere ok, procediamo con gli altri 
			for (k = 1; k < wordLength; k++)
			{
				// Rimaniamo entro i limiti della matrice
				if (r < 0 || r >= _rows || c < 0 || c >= _cols)
				{
					break;
				}

				if (_charMatrix[r][c] != word[k])
				{
					break;
				}

				// Avanziamo nella matrice dei caratteri lungo una specifica direzione,
				// un passo alla volta.
				r += _dirOffsets[dir].x;
				c += _dirOffsets[dir].y;
			}

			// Se non siamo usciti prematuramente dal ciclo precedente,
			// abbiamo trovato la nostra parola
			if (k == wordLength)
			{
				foundAlong = _dirOffsets[dir];
				return true;
			}
		}

		return false;
	}
}