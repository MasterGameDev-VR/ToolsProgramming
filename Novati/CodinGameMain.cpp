#include "pch.h"
#include "AsciiArtStringTest.cpp"

namespace CodinGame {
	int main()
	{
		int project;
		int test_case;
		int exit = 0;

		std::cout << "Andrea Novati - Tools programming MasterGameDev 2018-2019\n\n";

		std::cout << "1) AsciiArt (medium)\n";
		std::cout << "2) Mars\n";
		std::cout << "3) Quit\n\n";

		AsciiArtStringTest *test;

		while (!exit) {
			std::cout << "Choose Project: ";
			cin >> project;
			switch (project) {
			case 1: {


				cin >> test_case;

				switch (test_case) {
				case 1: {
					test = new AsciiArtStringTest("AsciiArt01.txt");
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				case 5: {
					break;
				}
				default: {
					std::cout << "\nYOUR ARGUMENT HAS NEVER BEEN SO INVALID";
				}
				};



				break;
			}
			case 2: {
				cin >> test_case;

				//break;
			}
			case 3: {
				std::cout << "\nQUIT";
				exit = 1;
				break;
			}
			default: {
				std::cout << "\nYOUR ARGUMENT IS INVALID";
			}
			};

			test->Execute();

		}
	}
}