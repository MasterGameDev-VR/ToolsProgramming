#pragma once
#include <iostream>

#include "AsciiArt/AsciiArtString.h"

using namespace AsciiArt;

namespace CodinGame {

	class AsciiArtStringTest {
	protected:
		AsciiArtString *str;
		std::string _INPUT_FILENAME;
	
	public:
		AsciiArtStringTest();

		~AsciiArtStringTest();

		AsciiArtStringTest(const std::string INPUT_FILENAME);

		AsciiArtStringTest(const char* INPUT_FILENAME);
	
		void Execute();
	
	private:
		void Init(const std::string INPUT_FILENAME);

	};
}