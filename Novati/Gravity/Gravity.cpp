// Gravity.cpp : Defines the exported functions for the DLL application.
#include "stdafx.h"
#include "Gravity.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace GravityGM {

	Gravity::Gravity(const string INPUT_FILENAME) {
		int width;
		int height;
		
		wchar_t  path_buffer[255];
		GetModuleFileName(NULL, path_buffer, 255);
		wstring ws(path_buffer);
		// your new String
		string str(ws.begin(), ws.end());
		string::size_type pos = string(str).find_last_of("\\/");
		string path = string(str).substr(0, pos);

		string _INPUT_FILENAME = path + "\\" + INPUT_FILENAME;

		vector<string> INPUT_ROWS;

		ifstream input(_INPUT_FILENAME);
		
		input >> width >> height;


		char *new_map = new char[height*width];

		for (int i = 0; i < height; i++) {
			string line;
			input >> line;

			auto linec = line.c_str();

			for (int j = 0; j < width; j++)
				*(new_map + (i*width) + j) = linec[j];
		}

		InitGravity(height, width, new_map);
	}

	void Gravity::InitGravity(int H, int W,char *M) {
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
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
				cout << *(map + (i*width) + j);

			cout << "\n";
		}
		cout << "\n";
	}
}