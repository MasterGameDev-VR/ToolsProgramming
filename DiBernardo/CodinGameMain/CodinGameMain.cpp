// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "..\StockExchangeLosses\StockExchangeLosses.h"
#include "..\ChuckNorris\ChuckNorris.h"

void chuck() {
	ChuckNorris chuck("..\\ChuckNorris.txt");
	std::cout << "ChuckNorris: ";
	chuck.Execute();
}

void stock() {
	StockExchangeLosses stock("..\\StockExchangeLosses.txt");
	std::cout << "StockExchangeLosses: ";
	stock.Execute();
}

int main(){
	char choice;

	std::cout << "Selezionare esercizio: \n1) Stock Exchange Losses \n2) Chuck Norris" << std::endl;
	std::cin >> choice;

	switch (choice){
	case '1':
		stock();
		break;
	case '2':
		chuck();
		break;
	default:
		std::cout << "Unknown choice";
		break;
	}

}


