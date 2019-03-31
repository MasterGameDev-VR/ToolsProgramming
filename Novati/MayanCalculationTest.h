#pragma once
#include <iostream>

#include "MayanCalculation.h"

namespace CodinGame {

	class MayanCalculationTest {
	protected:
		MayanCalculation *str;
		std::string _INPUT_FILENAME;

	public:
		MayanCalculationTest();

		~MayanCalculationTest();

		MayanCalculationTest(const std::string INPUT_FILENAME);

		MayanCalculationTest(const char* INPUT_FILENAME);

		void Execute();

	private:
		void Init(const std::string INPUT_FILENAME);

	};
}