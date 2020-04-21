#include "../Temperatures/Temperatures.h"
#include "../Horse-racing Duals/HorseRacingDuals.h"
#include <iostream>

const int temperatures_testCases = 6;
const int horseRacingDuals_testCases = 3;

int inputSelection(int maxTestCase) {
	std::cout << "Seleziona un input da 1 a " + std::to_string(maxTestCase) << std::endl;
	
	int input_selection;
	std::cin >> input_selection; std::cin.ignore();
	if (input_selection < 1 || input_selection > maxTestCase) {
		std::cout << "Selezione errata.";
		return -1;
	}

	return input_selection;
}

void temperatures() {
	int input_selection = inputSelection(temperatures_testCases);
	if (input_selection < 0) return;
	std::cout << "> Test " + std::to_string(input_selection) + ": ";
	Temperatures temp("../Temperatures/TestCases/Temperatures_" + std::to_string(input_selection) + ".txt");
	temp.Execute();
}

void horseRacingDuals() {
	int input_selection = inputSelection(horseRacingDuals_testCases);
	if (input_selection < 0) return;
	std::cout << "> Test " + std::to_string(input_selection) + ": ";
	HorseRacingDuals horseRacing("../Horse-racing Duals/TestCases/Horse-racingDuals_" + std::to_string(input_selection) + ".txt");
	horseRacing.Execute();
}

void runAll() {
	std::cout << "Esecuzione Temperatures:" << std::endl;
	for (int i = 1; i <= temperatures_testCases; i++)
	{
		std::cout << "> Test " + std::to_string(i) + ": ";
		Temperatures temp("../Temperatures/TestCases/Temperatures_" + std::to_string(i) + ".txt");
		temp.Execute();
	}
	std::cout << "Esecuzione Horse-racing Duals:" << std::endl;
	for (int i = 1; i <= horseRacingDuals_testCases; i++)
	{
		std::cout << "> Test " + std::to_string(i) + ": ";
		HorseRacingDuals horseRacing("../Horse-racing Duals/TestCases/Horse-racingDuals_" + std::to_string(i) + ".txt");
		horseRacing.Execute();
	}
}

int main()
{
	std::cout << "Selezionare esercizio:" << std::endl;
	std::cout << "0 - Esegui tutti" << std::endl;
	std::cout << "1 - Temperatures" << std::endl;
	std::cout << "2 - Horse-racing Duals" << std::endl;

	int exercise_selection;
	std::cin >> exercise_selection; std::cin.ignore();

	switch (exercise_selection) {
	case 0:
		runAll();
		break;
	case 1:
		temperatures();
		break;
	case 2:
		horseRacingDuals();
		break;
	default:
		std::cout << "Selezione errata.";
	}
}
