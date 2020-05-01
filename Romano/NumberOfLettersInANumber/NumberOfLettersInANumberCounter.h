#pragma once
#include <string>
#include <fstream>
#include <iostream>

namespace NumberOfLettersInANumber
{
	class NumberOfLettersInANumberCounter
	{
	public:
		NumberOfLettersInANumberCounter(const std::string& filePath);
		static unsigned CountSetBits(long long n, unsigned& numSignificantBits);
		void Execute();

		long long GetStart() const { return _start; }
		long long GetN() const { return _n; }
	private:
		long long _start;
		long long _n;
	};
}