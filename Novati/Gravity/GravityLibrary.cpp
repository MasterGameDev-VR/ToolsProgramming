#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Gravity.h"
#include "GravityLibrary.h"


using namespace std;
using namespace GravityGM;

static Gravity *g;
static string _INPUT_FILENAME;


VOID APIENTRY ConstructTest(const string INPUT_FILENAME) {
	g = new Gravity(INPUT_FILENAME);
}

VOID APIENTRY ReleaseTest() {
	delete g;
}

VOID APIENTRY  ExecuteTest() {
	cout << "Execute " << _INPUT_FILENAME << "\n";
	g->Resolve();
}

BOOL APIENTRY DllMain(HMODULE hModule,
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
