#include "pch.h"
#include <iostream>
#include "AsciiArtStringTest.h"
#include "MayanCalculationTest.h"
#include "GameOfLifeLibrary.h"

#include <windows.h>

using namespace std;
using namespace CodinGame;

typedef int(__stdcall *f_funci)();

typedef GAMEOFLIFE_API void (*ConstructTestFunction)(const string INPUT_FILENAME);
//typedef void(*ConstructTestFunction)(const string INPUT_FILENAME);
typedef GAMEOFLIFE_API void (*ExecuteTestFunction)();
typedef GAMEOFLIFE_API void (*ReleaseTestFunction)();

	int main()
	{
		ConstructTestFunction ConstructTest;
		ExecuteTestFunction ExecuteTest;
		ReleaseTestFunction ReleaseTest;
		DWORD last_error;

		int project;
		int test_case;
		int exit = 0;

		cout << "Andrea Novati - Tools programming MasterGameDev 2018-2019\n\n";

		cout << "1) AsciiArt (easy)\n";
		cout << "2) GameOfLife (medium)\n";
		cout << "3) Gravity (medium)\n";
		cout << "4 NEW!) Mayan Calculation(medium)\n";
		cout << "5) Quit\n\n";

		int test_selected = 0;
		while (!exit) {
			cout << "Choose Project: ";
			cin >> project;
			AsciiArtStringTest *test = NULL;
			MayanCalculationTest *m_test = NULL;

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

				HMODULE  dllHandle = LoadLibrary(L"GameOfLife.dll");

				if (!dllHandle) {
					cout << "Error loading dll file GameOfLife.dll ";
					return -1;
				}

				ExecuteTest = (ExecuteTestFunction)GetProcAddress(dllHandle, "ExecuteTest");

				last_error = GetLastError();
				if (last_error) {
					cout << "Error loading ExecuteTest proc " << last_error;
					return -1;
				}

				ConstructTest = (ConstructTestFunction)GetProcAddress(dllHandle, "ConstructTest");
				last_error = GetLastError();
				if (last_error) {
					cout << "Error loading ConstructTest proc " << last_error;
					return -1;
				}

				ReleaseTest = (ReleaseTestFunction)GetProcAddress(dllHandle, "ReleaseTest");
				last_error = GetLastError();
				if (last_error) {
					cout << "Error loading ReleaseTest proc " << last_error;
					return -1;
				}
				
				switch (test_case) {
				case 1: {
					ConstructTest("GameOfLife01.txt");
					test_selected = 1;

					break;
				}
				case 2: {
					ConstructTest("GameOfLife02.txt");
					test_selected = 1;

					break;
				}
				case 3: {
					ConstructTest("GameOfLife03.txt");
					test_selected = 1;

					break;
				}
				case 4: {
					ConstructTest("GameOfLife04.txt");
					test_selected = 1;

					break;
				}
				case 5: {
					ConstructTest("GameOfLife05.txt");
					test_selected = 1;

					break;
				}
				case 6: {
					ConstructTest("GameOfLife06.txt");
					test_selected = 1;

					break;
				}
				case 7: {
					ConstructTest("GameOfLife07.txt");
					test_selected = 1;

					break;
				}
				default: {
					cout << "\nYOUR ARGUMENT HAS NEVER BEEN SO INVALID";
					break;
				}
				};
				
				
				if (test_selected == 1)
					ExecuteTest();

				ReleaseTest();
				FreeLibrary(dllHandle);
				break;
			}
			case 3: {
				cout << "Choose a test case [1-5]: ";
				cin >> test_case;

				HMODULE  dllHandle = LoadLibrary(L"Gravity.dll");

				if (!dllHandle) {
					cout << "Error loading dll file Gravity.dll ";
					return -1;
				}

				ExecuteTest = (ExecuteTestFunction)GetProcAddress(dllHandle, "ExecuteTest");

				last_error = GetLastError();
				if (last_error) {
					cout << "Error loading ExecuteTest proc " << last_error;
					return -1;
				}

				ConstructTest = (ConstructTestFunction)GetProcAddress(dllHandle, "ConstructTest");
				last_error = GetLastError();
				if (last_error) {
					cout << "Error loading ConstructTest proc " << last_error;
					return -1;
				}

				ReleaseTest = (ReleaseTestFunction)GetProcAddress(dllHandle, "ReleaseTest");
				last_error = GetLastError();
				if (last_error) {
					cout << "Error loading ReleaseTest proc " << last_error;
					return -1;
				}

				switch (test_case) {
				case 1: {
					ConstructTest("Gravity01.txt");
					test_selected = 1;

					break;
				}
				case 2: {
					ConstructTest("Gravity02.txt");
					test_selected = 1;

					break;
				}
				case 3: {
					ConstructTest("Gravity03.txt");
					test_selected = 1;

					break;
				}
				case 4: {
					ConstructTest("Gravity04.txt");
					test_selected = 1;

					break;
				}
				case 5: {
					ConstructTest("Gravity05.txt");
					test_selected = 1;

					break;
				}
				default: {
					cout << "\nYOUR ARGUMENT HAS NEVER BEEN SO INVALID";
					break;
				}
				};


				if (test_selected == 1)
					ExecuteTest();

				ReleaseTest();
				FreeLibrary(dllHandle);
				break;
			}
			case 4: {
				cout << "Choose a test case [1-12]: ";
				cin >> test_case;
				switch (test_case) {
				case 1: {
					m_test = new MayanCalculationTest("MayanCalculation01.txt");
					test_selected = 2;

					break;
				}
				case 2: {
					m_test = new MayanCalculationTest("MayanCalculation02.txt");
					test_selected = 2;

					break;
				}
				case 3: {
					m_test = new MayanCalculationTest("MayanCalculation03.txt");
					test_selected = 2;

					break;
				}
				case 4: {
					m_test = new MayanCalculationTest("MayanCalculation04.txt");
					test_selected = 2;

					break;
				}
				case 5: {
					m_test = new MayanCalculationTest("MayanCalculation05.txt");
					test_selected = 2;

					break;
				}
				case 6: {
					m_test = new MayanCalculationTest("MayanCalculation06.txt");
					test_selected = 2;

					break;
				}
				case 7: {
					m_test = new MayanCalculationTest("MayanCalculation07.txt");
					test_selected = 2;

					break;
				}
				case 8: {
					m_test = new MayanCalculationTest("MayanCalculation08.txt");
					test_selected = 2;

					break;
				}
				case 9: {
					m_test = new MayanCalculationTest("MayanCalculation09.txt");
					test_selected = 2;

					break;
				}
				case 10: {
					m_test = new MayanCalculationTest("MayanCalculation10.txt");
					test_selected = 2;

					break;
				}
				case 11: {
					m_test = new MayanCalculationTest("MayanCalculation11.txt");
					test_selected = 2;

					break;
				}
				case 12: {
					m_test = new MayanCalculationTest("MayanCalculation12.txt");
					test_selected = 2;

					break;
				}
				default: {
					cout << "\nYOUR ARGUMENT HAS NEVER BEEN SO INVALID";
					break;
				}
				};

				if (test_selected == 1)
					test->Execute();

				if (test_selected == 2)
					m_test->Execute();
				break;
			}
			case 5: {
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