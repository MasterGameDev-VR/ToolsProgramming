#pragma once
#include <vector>
#include <string>

using namespace std;

namespace GravityGM {

	class Gravity {
	private:
		int width;
		int height;

		char* map;

	public:
		
		Gravity(const string INPUT_FILENAME);

		void InitGravity(int W, int H, char *map);
		
		~Gravity();

		void ApplyOneStep();

		bool CheckGravity();

		void PrintMap();

		char * Resolve();
	};
}