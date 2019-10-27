#include "pch.h"
#include "framework.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include "TheGift.h"

TheGift::TheGift(const std::string& filename)
	: m_budgets()
{
	std::ifstream in(filename);
	auto backup = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());

	std::cin >> m_nParticipants; std::cin.ignore();
	std::cin >> m_cost; std::cin.ignore();
	
	for (int i = 0; i < m_nParticipants; ++i)
	{
		int budget;
		std::cin >> budget; std::cin.ignore();

		m_budgets.push(budget);
	}

	std::cin.rdbuf(backup);
}

void TheGift::Execute()
{
	std::vector<int> contributions;

	int remainingCost = m_cost;
	while (m_budgets.size() > 0)
	{
		int minBudget = m_budgets.top();
		int nBudgets = m_budgets.size();

		int contribution = std::min((remainingCost / nBudgets), minBudget);
		if (contribution > minBudget)
			break;

		contributions.push_back(contribution);

		remainingCost -= contribution;
		m_budgets.pop();
	}

	if (contributions.size() == m_nParticipants && remainingCost == 0) {
		for (auto contribution : contributions)
			std::cout << contribution << std::endl;
	}
	else {
		std::cout << "IMPOSSIBLE" << std::endl;
	}
}