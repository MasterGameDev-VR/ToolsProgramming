#include "stdafx.h"
#include "NumberOfLettersInANumberCounter.h"

namespace NumberOfLettersInANumber
{
	NumberOfLettersInANumberCounter::NumberOfLettersInANumberCounter(const std::string& filePath)
	{
		std::ifstream input(filePath);
		auto cinbuf = std::cin.rdbuf(input.rdbuf());

		std::cin >> _start >> _n; 
		std::cin.ignore();
	}

	void
	NumberOfLettersInANumberCounter::Execute()
	{
		long long si = _start;
		unsigned numLetters = 0;
		unsigned oldNumLetters = 0;
		for (int i = 0; i < _n; i++)
		{
			unsigned significantBits = 0;
			unsigned ones = CountSetBits(si, significantBits);
			unsigned zeroes = significantBits - ones;

			oldNumLetters = numLetters;
			numLetters = ones * 3 + zeroes * 4; // "one" = 3 lettere, "zero" = 4 lettere

			// Può succedere che il numero di lettere corrispondenti a un numero
			// corrispondano al numero stesso, per cui le successive iterazioni
			// produrrebbero sempre lo stesso risultato.
			if (oldNumLetters == numLetters)
			{
				break;
			}

			si = numLetters;
		}

		std::cout << numLetters;
	}

	// Restituisce il numero di bit settati a 1 in un intero e il numero di cifre significative
	// della configurazione binaria.
	unsigned 
	NumberOfLettersInANumberCounter::CountSetBits(long long num, unsigned& numSignificantBits)
	{
		unsigned count = 0;
		numSignificantBits = 0;

		// Finchè num è divero da zero...
		while(num)
		{
			// Conta un bit a 1 per ogni volta che il risultato dell'and bitwise
			// tra num e 1 è pari ad 1, cioè c'è un uno nell'ultima posizione di num.
			count += num & 1;

			// Incrementa il numero di cifre significative
			numSignificantBits++;

			// Shifta num di una posizione a destra per controllare anche le altre posizioni
			num >>= 1;
		}

		return count;
	}


}