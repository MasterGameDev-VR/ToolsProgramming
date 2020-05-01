#include "SkynetRevolution.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>


SkynetRevolution::SkynetRevolution(std::string filePath)
{
	std::ifstream inputFile;
	inputFile.open(filePath);

	std::string line;
	if (!inputFile.is_open())
	{
		throw std::runtime_error("file not found!");
	}

	// # data setup
	std::getline(inputFile, line);
	int n = std::stoi(line);
	
	_visited.assign(n, false);
	_parents.assign(n, -1);
	_graph.assign(n, std::vector<int>());
	_gateways.assign(1, 0);

	// edge setup
	while (std::getline(inputFile, line))
	{
		int n1 = std::stoi(line);
		std::getline(inputFile, line);

		int n2 = std::stoi(line);
		_edge(n1, n2);
	}

	inputFile.close();
}

void SkynetRevolution::Execute()
{
	int targetFound = _bfs(11);
	_printPath(targetFound);
}

std::vector<int> SkynetRevolution::_removeEdge(int start, int target)
{
	int tmpIndex = target;
	while (_parents[tmpIndex] == -1)
	{
		tmpIndex -= 1;
	}
	while (_parents[tmpIndex] != start)
	{
		tmpIndex = _parents[tmpIndex];
	}

	std::vector<int> edge;
	edge.push_back(_parents[tmpIndex]);
	edge.push_back(tmpIndex);

	// cout << tmpIndex << " " << parents[tmpIndex] << endl;

	return edge;
}

void SkynetRevolution::_edge(int a, int b)
{
	_graph[a].push_back(b);
	_graph[b].push_back(a);
}

int SkynetRevolution::_bfs(int startNode)
{
	std::fill(_parents.begin(), _parents.end(), -1);
	std::fill(_visited.begin(), _visited.end(), false);

	std::queue<int> q;

	q.push(startNode);
	_visited[startNode] = true;

	_parents[startNode] = -1;

	while (!q.empty()) {

		int f = q.front();
		q.pop();

		if (std::find(_gateways.begin(), _gateways.end(), f) != _gateways.end()) {
			std::vector<int> edge = _removeEdge(startNode, f);
			_graph[edge[0]].erase(std::remove(_graph[edge[0]].begin(), _graph[edge[0]].end(), edge[1]), _graph[edge[0]].end());
			_graph[edge[1]].erase(std::remove(_graph[edge[1]].begin(), _graph[edge[1]].end(), edge[0]), _graph[edge[1]].end());

			return f;
		}

		for (auto i = _graph[f].begin(); i != _graph[f].end(); i++) {
			if (!_visited[*i]) {
				q.push(*i);
				_visited[*i] = true;
				_parents[*i] = f;
			}
		}
	}
	return -1;
}

void SkynetRevolution::_printPath(int target)
{
	std::cout << "Path found: " << std::endl;

	int tmpIndex = target;
	while (_parents[tmpIndex] == -1)
	{
		tmpIndex -= 1;
	}
	while (_parents[tmpIndex] != -1)
	{
		std::cout << tmpIndex << " -> " << _parents[tmpIndex] << std::endl;
		tmpIndex = _parents[tmpIndex];
	}
}

SkynetRevolution::~SkynetRevolution()
{
}
