
#include "stdafx.h"
#include "War.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::streambuf;


int War::GetCardValue(std::string card)
{
	if (card[0] == 'A')
		return 14;
	if (card[0] == 'K')
		return 13;
	if (card[0] == 'Q')
		return 12;
	if (card[0] == 'J')
		return 11;
	if (card[0] == '1')
		return 10;

	return card[0] - 48;
}

War::War(std::string filePath)
{

	ifstream inputFileStream{ filePath };
	streambuf* inputBuffer = cin.rdbuf(inputFileStream.rdbuf());
	int n;// the number of cards for player 1
	deck1 = {};
	deck2 = {};
	int rounds = 0;
	bool pat = false;
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		std::string cardp1; // the n cards of player 1
		cin >> cardp1; cin.ignore();
		deck1.push_back(GetCardValue(cardp1));
		//cerr << to_string(deck1[deck1.size()-1])<< endl;
	}
	int m; // the number of cards for player 2
	cin >> m; cin.ignore();
	for (int i = 0; i < m; i++) {
		std::string cardp2; // the m cards of player 2
		cin >> cardp2; cin.ignore();
		deck2.push_back(GetCardValue(cardp2));
	}
}

void War::Execute()
{
	while (!pat && deck1.size() && deck2.size())
	{
		if (deck1[0] > deck2[0])
		{
			deck1.push_back(deck1[0]);
			deck1.push_back(deck2[0]);
			deck1.erase(deck1.begin());
			deck2.erase(deck2.begin());
			rounds++;
			continue;
		}
		if (deck1[0] < deck2[0])
		{
			deck2.push_back(deck1[0]);
			deck2.push_back(deck2[0]);
			deck1.erase(deck1.begin());
			deck2.erase(deck2.begin());
			rounds++;
			continue;
		}
		int warwinner = 0;
		int warnumber = 1;
		while (!pat && !warwinner)
		{
			if (deck1.size() < warnumber * 4 || deck2.size() < warnumber * 4)
			{
				pat = true;
				continue;
			}
			if (deck1[warnumber * 4] > deck2[warnumber * 4])
			{
				warwinner = 1;
			}
			else
			{
				if (deck1[warnumber * 4] < deck2[warnumber * 4])
				{
					warwinner = 2;
				}
				else
				{
					warnumber++;
				}
			}
		}
		if (!pat && warwinner != 0)
		{
			if (warwinner == 1)
			{
				deck1.insert(deck1.end(), deck1.begin(), deck1.begin() + 1 + 4 * warnumber);
				deck1.insert(deck1.end(), deck2.begin(), deck2.begin() + 1 + 4 * warnumber);
				deck1.erase(deck1.begin(), deck1.begin() + 1 + 4 * warnumber);
				deck2.erase(deck2.begin(), deck2.begin() + 1 + 4 * warnumber);
			}
			else
			{
				deck2.insert(deck2.end(), deck1.begin(), deck1.begin() + 1 + 4 * warnumber);
				deck2.insert(deck2.end(), deck2.begin(), deck2.begin() + 1 + 4 * warnumber);
				deck1.erase(deck1.begin(), deck1.begin() + 1 + 4 * warnumber);
				deck2.erase(deck2.begin(), deck2.begin() + 1 + 4 * warnumber);
			}
			warnumber = 0;
			warwinner = 0;
			rounds++;
		}
	}
	if (pat)
	{
		cout << "PAT" << endl;
	}
	else
	{
		if (deck1.size())
		{
			cout << "1 " + std::to_string(rounds) << endl;
		}
		else
		{
			cout << "2 " + std::to_string(rounds) << endl;
		}
	}
}
