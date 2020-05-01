// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "GameOfLifeGM.h"
#include "GameOfLifeLibrary.h"

using namespace std;
using namespace GameOfLife;

static GameOfLifeGM *gol;
static string _INPUT_FILENAME;

VOID APIENTRY ConstructTest(const string INPUT_FILENAME) {
	gol = new GameOfLifeGM(INPUT_FILENAME);
}

VOID APIENTRY ReleaseTest() {
	delete gol;
}

/*VOID APIENTRY  ConstructTest(const char* INPUT_FILENAME) {
	gol = new GameOfLifeGM(string(INPUT_FILENAME));
}*/



VOID APIENTRY  ExecuteTest() {
	cout << "Execute " << _INPUT_FILENAME << "\n";
	gol->computeNext();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

