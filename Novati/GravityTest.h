#pragma once
#include <iostream>
#include <string>
#include "Gravity/Gravity.h"

using namespace GravityGM;

namespace CodinGame {
	class GravityTest {
	protected:
		Gravity *g;
		std::string _INPUT_FILENAME;

	public:
		GravityTest();

		~GravityTest();

		GravityTest(const std::string INPUT_FILENAME);

		GravityTest(const char* INPUT_FILENAME);

		void Execute();

	private:
		void Init(const std::string INPUT_FILENAME);

	};
}
