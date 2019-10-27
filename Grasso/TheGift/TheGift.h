#pragma once

#include <string>
#include <queue>
#include <vector>


class TheGift
{
private:
	int m_nParticipants;
	int m_cost;
	std::priority_queue<int, std::vector<int>, std::greater<int>> m_budgets;

public:
	TheGift(const std::string& filename);
	void Execute();
};