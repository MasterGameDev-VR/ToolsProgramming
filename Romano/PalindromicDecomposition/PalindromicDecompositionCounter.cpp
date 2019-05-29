#include "stdafx.h"
#include "PalindromicDecompositionCounter.h"


namespace PalindromicDecomposition
{
	bool PalindromidDecompositionCounter::IsPalindrome(const std::string& str, int first, int last)
	{
		// Se c'è un solo carattere o viene passata una lunghezza negativa (si assume stringa vuota),
		// --> palindromo
		if (first == last || last < first)
		{
			return true;
		}

		// Se il primo e l'ultimo carattere non corrispondono,
		// non importa cosa c'è nel mezzo: la porzione considerata non è un palindromo
		if (str[first] != str[last])
		{
			return false;
		}

		// Se ci sono 2 o più caratteri, verifica che la porzione centrale
		// sia un palindromo
		if (first < last + 1)
		{
			return IsPalindrome(str, first + 1, last - 1);
		}

		return true;
	}

	// Versione iterativa del metodo di cui sopra
	bool PalindromidDecompositionCounter::IsPalindromeIterative(const std::string& str, int first, int last)

	{
		const int length = first - last + 1;
		const int halfLength = length / 2;

		if (length < 1)
		{
			return true;
		}

		if (str[first] != str[last])
		{
			return false;
		}

		for (int i = 0; i <= halfLength; i++)
		{
			if (str[i] != str[length - i - 1])
			{
				return false;
			}
		}

		return true;
	}

	PalindromidDecompositionCounter::PalindromidDecompositionCounter(const std::string& filePath)
	{
		std::ifstream input(filePath);
		auto cinbuf = std::cin.rdbuf(input.rdbuf());

		std::getline(std::cin, _word);
	}

	void PalindromidDecompositionCounter::Execute()
	{
		const int length = _word.length();
		int cnt = 0;

		for (int i = -1; i < length; i++)
		{
			const int firstSubLength = (i + 1) > length ? length : (i + 1);

			//cout << "i= " << i << " , Considering: " << str.substr(0, firstSubLength) << endl;

			if (IsPalindrome(_word, 0, i))
			{
				//cout << "First decomp: " << str.substr(0, firstSubLength) << endl;

				const int secondStart = firstSubLength;
				for (int j = secondStart - 1; j < length; j++)
				{
					const int secondSubLength = (j - secondStart + 1) > length ?
						length : j - secondStart + 1;

					//cout << "i= " << i << " , j = " << j << " , Considering: " << str.substr(secondStart, secondSubLength) << endl;

					if (IsPalindrome(_word, secondStart, j))
					{
						//cout << "Second decomp: " << str.substr(secondStart, secondSubLength) << endl;

						int thirdStart = (secondStart + secondSubLength) > length ?
							length : (secondStart + secondSubLength);

						int thirdSubLength = length - thirdStart;

						//cout << "Considering: " << str.substr(thirdStart, thirdSubLength) << endl;

						// Se c'è un palindromo con quello che resta...
						if (IsPalindrome(_word, thirdStart, length - 1))
						{
							//cout << "Third decomp: " << str.substr(thirdStart, thirdSubLength) << endl;
							cnt++;
						}
					}
				}
			}
		}

		std::cout << cnt;

	}
}