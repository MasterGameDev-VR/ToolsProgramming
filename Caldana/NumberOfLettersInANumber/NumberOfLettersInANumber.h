#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "stdafx.h"

using namespace std;

namespace NumberOfLettersInANumberNS
{
	class NumberOfLettersInANumber
	{
	public:

		NumberOfLettersInANumber(string fileName)
		{
			ifstream input(fileName);
			auto cinbuf = cin.rdbuf(input.rdbuf());
			cin >> start >> n; cin.ignore();
		}

		~NumberOfLettersInANumber(){}

		void Execute()
		{
			long long i = 0;
			long long counter;
			while (i < n)
			{
				counter = to_binary(start);
				if (start == counter)
					break;
				start = counter;
				i++;
			}
			cout << start << endl;
		}

		long long to_binary(long long a)
		{
			long long counter = 0;
			long double log_n = log2(a);
			long long bit = floor(log2(a));
			for (long long i = bit; i >= 0; i--) {
				long long k = a >> i;
				if (k & 1)
					counter += 3;
				else
					counter += 4;
			}
			return counter;
		}

	private:
		long long start;
		long long n;
		
	};
}