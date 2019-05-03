// CodinGameMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <filesystem>
#include "..\StockExchangeLosses\StockExchangeLosses.h"
#include "..\ChuckNorris\ChuckNorris.h"

namespace fs = std::filesystem;

void chuck();
void stock();

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

void chuck() {
	std::string path = "..\\TestChuck";
	for (const auto & entry : fs::directory_iterator(path)) {
		ChuckNorris chuck(entry.path().u8string());
		std::cout << "Test: " << entry.path().u8string() << std::endl;
		chuck.Execute();
		std::cout << std::endl;
	}
}

void stock() {
	std::string path = "..\\TestStock";
	for (const auto & entry : fs::directory_iterator(path)) {
		StockExchangeLosses stock(entry.path().u8string());
		std::cout << "Test: " << entry.path().u8string() << std::endl;
		stock.Execute();
		std::cout << std::endl;
	}

}


