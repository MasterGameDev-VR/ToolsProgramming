#pragma once
#include <string>
#include <fstream>
#include <iostream>

namespace PalindromicDecomposition
{
	class PalindromidDecompositionCounter
	{
	public:
		PalindromidDecompositionCounter(const std::string& filePath);
		void Execute();
		static bool IsPalindrome(const std::string& str, int first, int last);
		static bool IsPalindromeIterative(const std::string& str, int first, int last);
		const std::string& GetWord() const { return _word; }
	private:
		std::string _word;
	};
}