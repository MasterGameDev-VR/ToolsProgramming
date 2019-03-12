#pragma once
#include <iostream>
#include <string>
#include "GameOfLife/GameOfLifeGM.h"

using namespace GameOfLife;

namespace CodinGame {

	class GameOfLifeTest {
	protected:
		GameOfLifeGM *gol;
		std::string _INPUT_FILENAME;

	public:
		GameOfLifeTest();

		~GameOfLifeTest();

		GameOfLifeTest(const std::string INPUT_FILENAME);

		GameOfLifeTest(const char* INPUT_FILENAME);

		void Execute();

	private:
		void Init(const std::string INPUT_FILENAME);

	};
}