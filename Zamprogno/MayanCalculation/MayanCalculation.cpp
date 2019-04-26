#include "stdafx.h"
#include "MayanCalculation.h"

#include <iostream>
#include <fstream>

using namespace std;

MayanCalculation::MayanCalculation(char *fileName)
{
	std::ifstream in(fileName);
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	cin >> L >> H; cin.ignore();
	for (int i = 0; i < 20; ++i)
		numbers.push_back(MayanNumber());

	for (int i = 0; i < H; i++) {
		string numeral;
		cin >> numeral; cin.ignore();
		for (int n = 0; n < 20; ++n)
			numbers[n].digit.push_back(numeral.substr(n*L, L));
	}

	cin >> S1; cin.ignore();
	for (int i = 0; i < S1 / H; ++i)
		firstMayanNumber.push_back(MayanNumber());

	for (int i = 0; i < S1; i++) {
		string num1Line;
		cin >> num1Line; cin.ignore();
		firstMayanNumber[i / H].digit.push_back(num1Line);
	}

	cin >> S2; cin.ignore();
	for (int i = 0; i < S2 / H; ++i)
		secondMayanNumber.push_back(MayanNumber());
	for (int i = 0; i < S2; i++) {
		string num2Line;
		cin >> num2Line; cin.ignore();
		secondMayanNumber[i / H].digit.push_back(num2Line);
	}
}

void MayanCalculation::Execute()
{
	double firstNumber = 0;
	for (int x = 0; x < S1 / H; ++x)
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < H; ++j)
			{
				if (firstMayanNumber[x].digit[j].compare(numbers[i].digit[j]) != 0)
					break;
				else if (j == H - 1)
					firstNumber += pow(20, (S1 / H) - (x + 1)) * i;
			}
		}

	double secondNumber = 0;
	for (int x = 0; x < S2 / H; ++x)
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < H; ++j)
			{
				if (secondMayanNumber[x].digit[j].compare(numbers[i].digit[j]) != 0)
					break;
				else if (j == H - 1)
					secondNumber += pow(20, (S2 / H) - (x + 1)) * i;
			}
		}

	string operation;
	cin >> operation; cin.ignore();
	if (operation.compare("+") == 0)
		firstNumber += secondNumber;
	else if (operation.compare("-") == 0)
		firstNumber -= secondNumber;
	else if (operation.compare("*") == 0)
		secondNumber *= firstNumber;
	else if (operation.compare("/") == 0)
		secondNumber /= firstNumber;

	vector<int> digits;
	double power = 1.0;

	do
	{
		int mod = (int)fmod(firstNumber, 20.0);
		digits.push_back(mod);
		modf(firstNumber / 20, &firstNumber);
	} while ((int)firstNumber > 0);


	for (auto digit : digits)
		for (int i = 0; i < H; ++i)
			cout << numbers[digit].digit[i] << endl;
}