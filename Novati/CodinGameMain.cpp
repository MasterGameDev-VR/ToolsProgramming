#include "pch.h"
#include <iostream>
#include "AsciiArtStringTest.h"
#include "GameOfLifeTest.h"

using namespace std;
using namespace CodinGame;

	int main()
	{
		int project;
		int test_case;
		int exit = 0;

		cout << "Andrea Novati - Tools programming MasterGameDev 2018-2019\n\n";

		cout << "1) AsciiArt (easy)\n";
		cout << "2) A_Star (medium)\n";
		cout << "3) GameOfLife (medium)\n";
		cout << "3) Quit\n\n";

		int test_selected = 0;
		while (!exit) {
			cout << "Choose Project: ";
			cin >> project;
			AsciiArtStringTest *test = NULL;

			switch (project) {
			case 1: {
				cout << "Choose a test case [1-5]: ";
				cin >> test_case;
				switch (test_case) {
				case 1: {
					test = new AsciiArtStringTest("AsciiArt01.txt");
					test_selected = 1;
						 
					break;
				}
				case 2: {
					test = new AsciiArtStringTest("AsciiArt02.txt");
					test_selected = 1;

					break;
				}
				case 3: {
					test = new AsciiArtStringTest("AsciiArt03.txt");
					test_selected = 1;

					break;
				}
				case 4: {
					test = new AsciiArtStringTest("AsciiArt04.txt");
					test_selected = 1;

					break;
				}
				case 5: {
					test = new AsciiArtStringTest("AsciiArt05.txt");
					test_selected = 1;

					break;
				}
				default: {
					cout << "\nYOUR ARGUMENT HAS NEVER BEEN SO INVALID";
					break;
				}
				};

				if (test_selected == 1)
					test->Execute();
				break;
			}
			case 2: {
				cout << "Choose a test case [1-7]: ";
				cin >> test_case;
				GameOfLifeTest *test1 = NULL;

				switch (test_case) {
				case 1: {
					test1 = new GameOfLifeTest("GameOfLife01.txt");
					test_selected = 1;

					break;
				}
				case 2: {
					test1 = new GameOfLifeTest("GameOfLife02.txt");
					test_selected = 1;

					break;
				}
				case 3: {
					test1 = new GameOfLifeTest("GameOfLife03.txt");
					test_selected = 1;

					break;
				}
				case 4: {
					test1 = new GameOfLifeTest("GameOfLife04.txt");
					test_selected = 1;

					break;
				}
				case 5: {
					test1 = new GameOfLifeTest("GameOfLife05.txt");
					test_selected = 1;

					break;
				}
				case 6: {
					test1 = new GameOfLifeTest("GameOfLife06.txt");
					test_selected = 1;

					break;
				}
				case 7: {
					test1 = new GameOfLifeTest("GameOfLife07.txt");
					test_selected = 1;

					break;
				}
				default: {
					cout << "\nYOUR ARGUMENT HAS NEVER BEEN SO INVALID";
					break;
				}
				};
				
				
				if (test_selected == 1)
					test1->Execute();

				break;
			}
			case 3: {
				cout << "\nQUIT";
				exit = 1;
				break;
			}
			default: {
				cout << "\nYOUR ARGUMENT IS INVALID";
				break;
			}
			};

			
		}

		return 0;
	}