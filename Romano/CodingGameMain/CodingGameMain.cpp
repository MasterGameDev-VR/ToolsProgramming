// CodingGameMain.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
#include <filesystem>

#include "HiddenWordStriker.h"
#include "NumberOfLettersInANumberCounter.h"
#include "PalindromicDecompositionCounter.h"

typedef std::vector<std::string> StringVector;

void GetPathsInDirectory(const std::string& directoryPath, StringVector& paths)
{
	for (auto& p : std::experimental::filesystem::directory_iterator(directoryPath))
		paths.push_back(p.path().string());
}

int main()
{
	const std::string hiddenWordTestsPrefix = "..\\Tests\\HiddenWord\\";
	const std::string numberOfLettersInANumberTestsPrefix = "..\\Tests\\NumberOfLettersInANumber\\";
	const std::string palindromicDecompositionTestsPrefix = "..\\Tests\\PalindromicDecomposition\\";

	{
		StringVector paths;

		GetPathsInDirectory(hiddenWordTestsPrefix, paths);

		std::cout << "Risultati (esercizio 1 - Hidden Word):" << std::endl;

		for (int i = 0; i < paths.size(); i++)
		{
			HiddenWord::HiddenWordStriker hWs(paths[i]);

			std::cout << "Test sample: " << paths[i] << std::endl;
			hWs.Execute();
			std::cout << std::endl;
		}
	}

	{
		StringVector paths;

		GetPathsInDirectory(numberOfLettersInANumberTestsPrefix, paths);

		std::cout << "\nRisultati (esercizio 2 - Number of letters in a number, binary):" << std::endl;

		for (int i = 0; i < paths.size(); i++)
		{
			NumberOfLettersInANumber::NumberOfLettersInANumberCounter nLn(paths[i]);

			std::cout << "Test sample: " << paths[i] << std::endl;
			nLn.Execute();
			std::cout << std::endl;
		}
	}

	{
		StringVector paths;

		GetPathsInDirectory(palindromicDecompositionTestsPrefix, paths);

		std::cout << "\nRisultati (esercizio 3 - Palindromic Decomposition):" << std::endl;

		for (int i = 0; i < paths.size(); i++)
		{
			PalindromicDecomposition::PalindromidDecompositionCounter pDc(paths[i]);

			std::cout << "Test sample: " << paths[i] << std::endl;
			pDc.Execute();
			std::cout << std::endl;
		}
	}

	return 0;
}

