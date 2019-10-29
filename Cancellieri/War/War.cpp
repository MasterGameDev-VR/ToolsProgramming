// War.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "War.h"


War::War(std::string testFile)
{
	std::ifstream in(testFile);
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	// store cards inside deck for player 1
	std::cin >> n; std::cin.ignore();
	std::string cardp1;
	for (int i = 0; i < n; i++)
	{
		std::cin >> cardp1; std::cin.ignore();
		deck1.push(PickValue(cardp1));
	}

	// store cards inside deck for player 2
	std::cin >> m; std::cin.ignore();
	std::string cardp2;
	for (int i = 0; i < m; i++)
	{
		std::cin >> cardp2; std::cin.ignore();
		deck2.push(PickValue(cardp2));
	}
}


void War::Execute()
{
	std::string winner = "";
	size_t rounds = 0;			// stores round played each game

	// auxiliary decks to store played cards on table to be won by one of the players
	std::queue<size_t> aux1;
	std::queue<size_t> aux2;

	// the player cards that take battle in current round
	size_t card1;
	size_t card2;

	bool gameOver = false;
	// game loop
	while (!gameOver)
	{
		rounds++;

		card1 = deck1.front();
		card2 = deck2.front();

		aux1.push(card1);
		aux2.push(card2);

		// Player 1 wins battle
		if (card1 > card2)
		{
			// win player1 cards on table first
			for (size_t i = 0; i < aux1.size(); i++)
			{
				deck1.push(aux1.front());
				aux1.pop();
			}
			// win player2 cards on table second
			for (size_t i = 0; i < aux2.size(); i++)
			{
				deck1.push(aux2.front());
				aux2.pop();
			}
			// delete currently played cards
			deck1.pop();
			deck2.pop();

			// check if player2 runs out of cards after a loss
			if (deck2.empty())
			{
				winner = "1";
				gameOver = true;
			}
		}
		// Player 2 wins battle
		else if (card1 < card2)
		{
			// win player1 cards on table first
			for (size_t i = 0; i < aux1.size(); i++)
			{
				deck2.push(aux1.front());
				aux1.pop();
			}
			// win player2 cards on table second
			for (size_t i = 0; i < aux2.size(); i++)
			{
				deck2.push(aux2.front());
				aux2.pop();
			}
			// delete currently played cards
			deck1.pop();
			deck2.pop();

			// check if player1 runs out of cards after a loss
			if (deck1.empty())
			{
				winner = "2";
				gameOver = true;
			}
		}
		// WAR
		else
		{
			rounds--;
			for (size_t i = 0; i < 4; i++)       // 3 + the cards that were equal
			{
				aux1.push(deck1.front());
				aux2.push(deck2.front());

				deck1.pop();
				deck2.pop();

				// special case ==> it's a draw
				if (deck1.empty() || deck2.empty())
				{
					winner = "PAT";
					gameOver = true;
					break;
				}
			}
		}
	}

	if (winner != "PAT")
	{
		std::cout << std::endl << "Winner : " << winner << " , Rounds : " << rounds <<  std::endl;
		std::cout << std::endl << "===================================" << std::endl;
	}
	else
	{
		std::cout << std::endl << winner << std::endl;
		std::cout << std::endl << "===================================" << std::endl;
	}

}

// function to convert string cards into values
size_t War::PickValue(std::string card)
{
	size_t value;

	const char& cardValue = card.at(0);

	// if it's a figure
	if (cardValue == 'J')
		value = 11;
	else if (cardValue == 'Q')
		value = 12;
	else if (cardValue == 'K')
		value = 13;
	else if (cardValue == 'A')
		value = 14;
	// if it's a number
	else
		value = std::stoi(card);

	return value;
}
