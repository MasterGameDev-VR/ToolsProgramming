#include "TheGift.h"
#include "War.h"
#include <iostream>


struct Exercise
{
	std::string m_name;

	std::string m_testsBaseDir;
	std::string m_testsBaseFile;
	std::string m_testsExtension;

	short int m_maxTests;

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
	exercises[0] = { "The Gift", "..\\TheGift\\Tests", "TheGift_", "txt", 9, &RunExercise<TheGift> };
	exercises[1] = { "War", "..\\War\\Tests", "War_", "txt", 9, &RunExercise<War> };

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

		if (action > 0 && action <= MAX_EXERCISES)
		{
			const int exerciseId = action - 1;
			Exercise& exercise = exercises[exerciseId];
			
			short int testId;
			std::cout << "Inserisci il nr. test [1 - " << exercise.m_maxTests << "]: ";
			std::cin >> testId;

			if (testId > 0 && testId <= exercise.m_maxTests)
			{
				std::cout << "\nSoluzione:" << std::endl;

				std::string filename = exercise.m_testsBaseDir;
				filename.append("\\");
				filename.append(exercise.m_testsBaseFile);
				filename.append(std::to_string(testId));
				filename.append(".");
				filename.append(exercise.m_testsExtension);

				exercise.m_run(filename);
			}
			else
			{
				std::cout << "Valore non valido" << std::endl;
			}
		}
		else if (action != 0)
		{
			std::cout << "Valore non valido" << std::endl;
		}
		else
		{
			break;
		}

		std::cout << std::endl;
		system("pause");
	}
	while (action != 0);
}