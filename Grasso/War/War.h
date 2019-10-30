#pragma once

#ifdef WAR_EXPORTS
#define WAR_API __declspec(dllexport)
#else
#define WAR_API __declspec(dllimport)
#endif

class War
{
private:
	std::queue<std::string> m_deck1;
	std::queue<std::string> m_deck2;

	void LoadDeck(std::queue<std::string>& deck);
	int GetValue(const std::string& card);
	int CompareCards(const std::string& card1, const std::string& card2);
	std::string  GetCard(std::queue<std::string>& deck);
	bool MoveCards(std::queue<std::string>& from, std::queue<std::string>& to, int n = -1);
	void ClearDeck(std::queue<std::string>& deck);
	std::queue<std::string>* StartFight(std::queue<std::string>& deck1, std::queue<std::string>& deck2);
	std::queue<std::string>* StartWar(std::queue<std::string>& deck1, std::queue<std::string>& deck2, std::queue<std::string>& war1, std::queue<std::string>& war2);

public:
	WAR_API War(const std::string& filename);
	WAR_API void Execute();
};
