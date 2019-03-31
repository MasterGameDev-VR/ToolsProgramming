#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "stdafx.h"

namespace NumberOfLettersInANumberNS
{
	class NumberOfLettersInANumber
	{
	public:

		NumberOfLettersInANumber(std::string& fileName);
		~NumberOfLettersInANumber() {};
		void Execute();
		long long to_binary(long long a);
		void SetValues(std::string& fileName);
	private:
		long long start;
		long long n;
	};
}