#include "pch.h"
#include <iostream>
#include "AsciiArtStringTest.h"

using namespace std;
using namespace CodinGame;

	int main()
	{
		int project;
		int test_case;
		int exit = 0;

		cout << "Andrea Novati - Tools programming MasterGameDev 2018-2019\n\n";

		cout << "1) AsciiArt (medium)\n";
		cout << "2) Mars\n";
		cout << "3) Quit\n\n";

		AsciiArtStringTest *test = NULL;

		while (!exit) {
			cout << "Choose Project: ";
			cin >> project;
			switch (project) {
			case 1: {
				cout << "Choose a test case [1-5]: ";


				cin >> test_case;

				switch (test_case) {
				case 1: {
					test = new AsciiArtStringTest("AsciiArt01.txt");
					break;
				}
				case 2: {
					test = new AsciiArtStringTest("AsciiArt02.txt");
					break;
				}
				case 3: {
					test = new AsciiArtStringTest("AsciiArt03.txt");
					break;
				}
				case 4: {
					test = new AsciiArtStringTest("AsciiArt04.txt");
					break;
				}
				case 5: {
					test = new AsciiArtStringTest("AsciiArt05.txt");
					break;
				}
				default: {
					cout << "\nYOUR ARGUMENT HAS NEVER BEEN SO INVALID";
				}
				};



				break;
			}
			case 2: {
				cin >> test_case;

				//break;
			}
			case 3: {
				cout << "\nQUIT";
				exit = 1;
				break;
			}
			default: {
				cout << "\nYOUR ARGUMENT IS INVALID";
			}
			};

			test->Execute();
			
			
		}

		return 0;
	}