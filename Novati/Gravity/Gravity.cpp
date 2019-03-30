// Gravity.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Gravity.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

namespace GravityGM {

	Gravity::Gravity(int W, int H,char *M) {
		width = W;
		height = H;

		map = M;
	}

	Gravity::~Gravity() {
	}

	void Gravity::ApplyOneStep() {
			for (int i = height - 1; i >= 1; i--)
				for (int j = 0; j < width; j++)
					if (*(map + ((i-1)*width) + j) == '#')
						if (*(map+(i*width)+j) == '.') {
							*(map + ((i-1)*width) + j) = '.';
							*(map + (i*width) + j) = '#';
						}
	}

	char *Gravity::Resolve() {
		do {
			ApplyOneStep();
			PrintMap();
		} while (CheckGravity());

		return map;
	}

	bool Gravity::CheckGravity() {
			for (int i = height - 1; i >= 1; i--)
				for (int j = 0; j < width; j++)
					if (*(map + ((i - 1)*width) + j) == '#')
						if (*(map + (i*width) + j) == '.') {
							return true;
						}
			return false;
	}

	void Gravity::PrintMap() {
		cout << "\n";
		cout << "\n";
		for (int i = height - 1; i > 1; i--) {
			for (int j = 0; j < width; j++)
				cout << *(map + (i*width) + j);

			cout << "\n";
		}
		cout << "\n";
	}
}