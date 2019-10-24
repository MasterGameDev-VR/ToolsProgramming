#pragma once

#include <queue>

#ifdef WAR_EXPORTS
#define WAR_API __declspec(dllexport)
#else
#define WAR_API __declspec(dllimport)
#endif

class War
{
public:
	WAR_API War(std::string testFile);
	WAR_API void Execute();

private:
	size_t PickValue(std::string card);

	// decks of the two players
	std::queue<size_t> deck1;
	std::queue<size_t> deck2;

	size_t n; // the number of cards for player1
	size_t m; // the number of cards for player2

};
