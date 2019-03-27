#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include <fstream>
#include "stdafx.h"


namespace NetworkCablingNS
{
	class NetworkCabling
	{
	public:
		NetworkCabling(std::string& fileName);

		~NetworkCabling() {}
		void Execute();
		void SetValues(std::string& fileName);
	private:
		int N;
		int x_positions[100000];
		int y_positions[100000];
		int x_min = std::numeric_limits<int>::max();
		int x_max = std::numeric_limits<int>::min();
		int y_min = std::numeric_limits<int>::max();
		int y_max = std::numeric_limits<int>::min();
	};
}
