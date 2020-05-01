#include "pch.h"
#include "framework.h"
#include <assert.h>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include "War.h"


War::War(const std::string& filename)
	: m_deck1()
	, m_deck2()
{
	std::ifstream in(filename);
	auto backup = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());

	LoadDeck(m_deck1);
	LoadDeck(m_deck2);

	std::cin.rdbuf(backup);
}

void War::LoadDeck(std::queue<std::string>& deck)
{
	int nCards;
	std::cin >> nCards; std::cin.ignore();

	for (int i = 0; i < nCards; ++i)
	{
		std::string card;
		std::cin >> card; std::cin.ignore();

		deck.push(card);
	}
}

void War::Execute()
{
	int round = 0;
	bool pat = false;
	while (!pat && !m_deck1.empty() && !m_deck2.empty())
	{
		++round;

		std::string fight1 = m_deck1.front();
		std::string fight2 = m_deck2.front();

		std::cerr << "Round " << round << std::endl;
		std::cerr << "- cards: " << m_deck1.size() << " - " << m_deck2.size() << std::endl;

		std::cerr << "- start fight: ";
		std::queue<std::string>* winner = StartFight(m_deck1, m_deck2);

		if (winner)
		{
			winner->push(fight1);
			winner->push(fight2);
		}
		else
		{
			std::queue<std::string> war1;
			war1.push(fight1);

			std::queue<std::string> war2;
			war2.push(fight2);

			do
			{
				std::cerr << "- start war: ";
				winner = StartWar(m_deck1, m_deck2, war1, war2);

				if (winner)
				{
					MoveCards(war1, *winner);
					MoveCards(war2, *winner);

					break;
				}
				else if ((war1.size() == 0 || war2.size() == 0))
				{
					pat = true;
					break;
				}

			}
			while (!m_deck1.empty() && !m_deck2.empty());
		}
	}

	std::cout << std::endl;

	if (!pat && !m_deck1.empty())
		std::cout << "1 " << round << std::endl;
	else if (!pat && !m_deck2.empty())
		std::cout << "2 " << round << std::endl;
	else
		std::cout << "PAT" << std::endl;
}

int War::GetValue(const std::string& card)
{
	int value;

	if (card.size() == 3)
	{
		value = 10;
	}
	else
	{
		switch (card[0])
		{
			case 'A': value = 14; break;
			case 'K': value = 13; break;
			case 'Q': value = 12; break;
			case 'J': value = 11; break;
			default:  value = card[0] - '0';
		}
	}

	return value;
}

int War::CompareCards(const std::string& card1, const std::string& card2)
{
	int value1 = GetValue(card1);
	int value2 = GetValue(card2);

	assert(value1 > 0);
	assert(value2 > 0); 

	std::cerr << card1 << " (" << value1 << ") vs " << card2 << " (" << value2 << ") -> ";

	if (value1 < value2)
	{
		std::cerr << "2" << std::endl;
		return -1;
	}
	else if (value1 > value2)
	{
		std::cerr << "1" << std::endl;
		return 1;
	}
	else
	{
		std::cerr << "0" << std::endl;
		return 0;
	}
}

std::string  War::GetCard(std::queue<std::string>& deck)
{
	std::string card = deck.front();
	deck.pop();

	return card;
}

bool War::MoveCards(std::queue<std::string>& from, std::queue<std::string>& to, int n /*= -1*/)
{
	if (n < 0)
		n = from.size();

	if (from.size() < n)
		return false;

	for (int i = 0; i < n; ++i)
	{
		const std::string& card = GetCard(from);
		to.push(card);
	}

	return true;
}

void War::ClearDeck(std::queue<std::string>& deck)
{
	int n = deck.size();
	for (int i = 0; i < n; ++i)
		deck.pop();
}

std::queue<std::string>* War::StartFight(std::queue<std::string>& deck1, std::queue<std::string>& deck2)
{
	const std::string& card1 = GetCard(deck1);
	const std::string& card2 = GetCard(deck2);

	int result = CompareCards(card1, card2);

	if (result > 0)
		return &deck1;
	else if (result < 0)
		return &deck2;
	else
		return nullptr;
}

std::queue<std::string>* War::StartWar(std::queue<std::string>& deck1, std::queue<std::string>& deck2, std::queue<std::string>& war1, std::queue<std::string>& war2)
{
	const int n = 3;
	if (
		!MoveCards(deck1, war1, n) || deck1.empty() ||
		!MoveCards(deck2, war2, n) || deck2.empty()
	){
		ClearDeck(war1);
		ClearDeck(war2);

		return nullptr;
	}

	const std::string& fight1 = deck1.front();
	war1.push(fight1);

	const std::string& fight2 = deck2.front();
	war2.push(fight2);

	std::queue<std::string>* winner = StartFight(deck1, deck2);
	return winner;
}