#include "stdafx.h"
#include "NetworkCabling.h"

NetworkCablingNS::NetworkCabling::NetworkCabling(std::string& fileName)
{
	SetValues(fileName);
}

void NetworkCablingNS::NetworkCabling::Execute()
{
	std::sort(y_positions, y_positions + N);

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



	std::cout << solution + (x_max - x_min) << std::endl;
}

void NetworkCablingNS::NetworkCabling::SetValues(std::string& fileName)
{
	std::ifstream input(fileName);
	auto cinbuf = std::cin.rdbuf(input.rdbuf());
	std::cin >> N; std::cin.ignore();
	for (int i = 0; i < N; i++)
	{
		std::cin >> x_positions[i] >> y_positions[i]; std::cin.ignore();
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
