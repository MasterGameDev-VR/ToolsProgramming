#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include <fstream>
#include "stdafx.h"

using namespace std;

namespace NetworkCablingNS
{
	class NetworkCabling
	{
	public:
		NetworkCabling(string fileName)
		{
			ifstream input(fileName);
			auto cinbuf = cin.rdbuf(input.rdbuf());
			cin >> N; cin.ignore();
			for (int i = 0; i < N; i++)
			{
				cin >> x_positions[i] >> y_positions[i]; cin.ignore();
				if (x_positions[i] < x_min)
					x_min = x_positions[i];
				if (x_positions[i] > x_max)
					x_max = x_positions[i];
				if (y_positions[i] < y_min)
					y_min = y_positions[i];
				if (y_positions[i] > y_max)
					y_max = y_positions[i];
			}
		}
		~NetworkCabling(){}
		void Execute()
		{
			sort(y_positions, y_positions + N);

			int y_pos;
			if (N % 2 == 1)
				y_pos = y_positions[N / 2];
			else
				y_pos = y_positions[(N / 2) - 1];

			long long solution = 0;
			for (int i = 0; i < N; i++)
			{
				solution += abs(y_positions[i] - y_pos);
			}



			cout << solution + (x_max - x_min) << endl;
		}
	private:
		int N;
		int x_positions[100000];
		int y_positions[100000];
		int x_min = numeric_limits<int>::max();
		int x_max = numeric_limits<int>::min();
		int y_min = numeric_limits<int>::max();
		int y_max = numeric_limits<int>::min();

	};
}
