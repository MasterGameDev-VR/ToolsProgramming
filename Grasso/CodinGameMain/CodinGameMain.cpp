#include "TheGift.h"
#include "War.h"
#include <iostream>


struct Exercise
{
	std::string m_name;
	std::string m_testFile;
	void (*m_run)(std::string);
};

template <typename T>
void RunExercise(std::string filename)
{
	T exercise(filename);
	exercise.Execute();
}

int main()
{
	const int MAX_EXERCISES = 2;
	Exercise exercises[MAX_EXERCISES];
	exercises[0] = { "The Gift", "..\\TheGift\\TheGift.txt", &RunExercise<TheGift> };
	exercises[1] = { "War", "..\\War\\War.txt", &RunExercise<War> };

	int action;
	do {
		system("cls");

		std::cout	<< "+-------------------------------+\n"
					<< "| MASTER GAMEDEV A.A. 2018/2019 |\n"
					<< "|                               |\n"
					<< "| PROGETTO DI TOOLS PROGRAMMING |\n"
					<< "+-------------------------------+\n\n";

		std::cout	<< "Esercizi disponibili:\n";
		for (int i = 0; i < MAX_EXERCISES; ++i)
			std::cout << (i + 1) << ") " << exercises[i].m_name << "\n";
		
		std::cout	<< "-------\n"
					<< "0) Esci\n"
					<< std::endl;

		std::cout << "Inserisci il nr. esercizio: ";
		std::cin >> action;

		if (action > 0 && action <= MAX_EXERCISES) {
			std::cout << "\nSoluzione:" << std::endl;

			const int id = action - 1;
			Exercise& exercise = exercises[id];

			exercise.m_run(exercise.m_testFile);
		}
		else if (action != 0) {
			std::cout << "Valore non valido" << std::endl;
		}
		else {
			break;
		}

		std::cout << std::endl;
		system("pause");
	}
	while (action != 0);
}