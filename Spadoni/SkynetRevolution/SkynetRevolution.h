#pragma once

#include <string>
#include <vector>
#include "IGame.h"

class SkynetRevolution : public IGame
{
public:
	__declspec(dllexport) SkynetRevolution(std::string filePath = "");
	__declspec(dllexport) void Execute();
	__declspec(dllexport) virtual ~SkynetRevolution();

private:
	int _bfs(int startNode);
	void _edge(int a, int b);
	std::vector<int> _removeEdge(int start, int target);
	void _printPath(int target);

	std::vector<bool> _visited;
	std::vector<int> _gateways;
	std::vector<int> _parents;
	std::vector<std::vector<int>> _graph;
};



