#include "stdafx.h"
#include "MayanCalculation.h"

#include <iostream>
#include <fstream>

using namespace std;

MayanCalculation::MayanCalculation(string fileName)
{
	//std::ifstream in(fileName);
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());

	ifstream input(fileName);

	input >> L >> H; input.ignore();
	for (int i = 0; i < 20; ++i)
		numbers.push_back(MayanNumber());

	for (int i = 0; i < H; i++) {
		string numeral;
		input >> numeral; input.ignore();
		for (int n = 0; n < 20; ++n)
			numbers[n].digit.push_back(numeral.substr(n*L, L));
	}

	input >> S1; input.ignore();
	for (int i = 0; i < S1 / H; ++i)
		firstMayanNumber.push_back(MayanNumber());

	for (int i = 0; i < S1; i++) {
		string num1Line;
		input >> num1Line; input.ignore();
		firstMayanNumber[i / H].digit.push_back(num1Line);
	}

	input >> S2; input.ignore();

	for (int i = 0; i < S2 / H; ++i)
		secondMayanNumber.push_back(MayanNumber());

	for (int i = 0; i < S2; i++) {
		string num2Line;
		input >> num2Line; input.ignore();
		secondMayanNumber[i / H].digit.push_back(num2Line);
	}

	operation;
	input >> operation; input.ignore();
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

	if (operation.compare("+") == 0)
		firstNumber += secondNumber;
	else if (operation.compare("-") == 0)
		firstNumber -= secondNumber;
	else if (operation.compare("*") == 0)
		firstNumber *= secondNumber;
	else if (operation.compare("/") == 0)
		firstNumber /= secondNumber;

	vector<int> digits;
	double power = 1.0;

	do
	{
		int mod = (int)fmod(firstNumber, 20.0);
		digits.push_back(mod);
		modf(firstNumber / 20.0, &firstNumber);
	} while ((int)firstNumber > 0);



	for (vector<int>::reverse_iterator i = digits.rbegin(); i != digits.rend(); i++)
		for (int j = 0; j < H; ++j)
			cout << numbers[*i].digit[j] << endl;
}