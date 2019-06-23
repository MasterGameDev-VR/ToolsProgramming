// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "../SumofDivisors/SumofDivisors.h"


void Divisors(int n);

int main()
{
	int nTest = 4;
	bool ext = false;
	char choise;
	auto chooseBuf = std::cin.rdbuf(); //Stream buffer usato per leggere la risposta dell'utente

	std::cout << "Progetto Tools Gullotta Mario.\n";

	while (!ext)
	{
		std::cout << "Digita 1 per selezionare il minigioco Sum of Divisors, 2 per il minigioco THESE ROMANS ARE CRAZY! o n per uscire\n";
		std::cin.rdbuf(chooseBuf);
		std::cin >> choise;
		std::cin.ignore();

		switch (choise)
		{
		case '1':
			std::cout << "Hai selezionato Sum of Divisors\n";
			Divisors(nTest);
			break;

		case '2':
			std::cout << "Hai selezionato THESE ROMANS ARE CRAZY\n";
			break;

		case 'n':
		case 'N':
			ext = true;
			break;

		default:
			std::cout << "Errore, scelta non corretta. Riprovare\n";
			break;
		}
	}
}

void Divisors(int n)
{
	for (int i = 1; i <= n; i++)
	{
		SumofDivisors SoM("..\\SumofDivisors\\SumOfDivisorsTest\\Test" + std::to_string(i) + ".txt");
		SoM.Execute();
	}
}
