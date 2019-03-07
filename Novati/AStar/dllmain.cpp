// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "AStarNode.h"

using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

vector<AStarNode> reconstruct_path(map< AStarNode, AStarNode>  cameFrom, AStarNode current) {
	vector<AStarNode> total_path = { current };

	/*
	while current in cameFrom.Keys:
		current := cameFrom[current]
		total_path.append(current)
	*/

	return total_path;
}

AStarNode* get_lower_node(vector< AStarNode> nodes, map< AStarNode, int> fScore) {
	AStarNode* lower;
	for (int i = 0; i < nodes.size(); i++) {
		if (lower == NULL)
		{
			lower = &nodes[i];
		}
		else
			if (fScore[nodes[i]] < fScore[*lower]) {
				lower = &nodes[i];
			}
	}

	return lower;
}

int heuristic_cost_estimate(AStarNode start, AStarNode goal) {
	return 1;
}


vector<AStarNode> A_Star(AStarNode start, AStarNode goal)
{

	AStarNode *current_node;
	// The set of nodes already evaluated
	vector<AStarNode> closedSet;
	
	// The set of currently discovered nodes that are not evaluated yet.
	// Initially, only the start node is known.
	vector<AStarNode> openSet = { start };

	// For each node, which node it can most efficiently be reached from.
	// If a node can be reached from many nodes, cameFrom will eventually contain the
	// most efficient previous step.
	map< AStarNode, AStarNode>  cameFrom; 

	// For each node, the cost of getting from the start node to that node.
	map< AStarNode, int> gScore;

	// The cost of going from start to start is zero.
	gScore[start] = 0;

	// For each node, the total cost of getting from the start node to the goal
	// by passing by that node. That value is partly known, partly heuristic.
	map< AStarNode, int> fScore;

	fScore[start] = heuristic_cost_estimate(start, goal);


	while (openSet.size() != 0) {
		//order nodes by lowest fScore[] value
		current_node = get_lower_node(openSet, fScore);

		if ( (*current_node) == goal)
			return reconstruct_path(cameFrom, *current_node);
	}
}





/*
function A_Star(start, goal)
// The set of nodes already evaluated
closedSet : = {}

	// The set of currently discovered nodes that are not evaluated yet.
	// Initially, only the start node is known.
openSet: = { start }

	// For each node, which node it can most efficiently be reached from.
	// If a node can be reached from many nodes, cameFrom will eventually contain the
	// most efficient previous step.
cameFrom: = an empty map

	// For each node, the cost of getting from the start node to that node.
	gScore : = map with default value of Infinity

	// The cost of going from start to start is zero.
	gScore[start] : = 0

	// For each node, the total cost of getting from the start node to the goal
	// by passing by that node. That value is partly known, partly heuristic.
	fScore : = map with default value of Infinity

	// For the first node, that value is completely heuristic.
	fScore[start] : = heuristic_cost_estimate(start, goal)

	while openSet is not empty
		current : = the node in openSet having the lowest fScore[] value
		if current = goal
			return reconstruct_path(cameFrom, current)

			openSet.Remove(current)
			closedSet.Add(current)

			for each neighbor of current
				if neighbor in closedSet
					continue		// Ignore the neighbor which is already evaluated.

				// The distance from start to a neighbor
					tentative_gScore : = gScore[current] + dist_between(current, neighbor)

					if neighbor not in openSet	// Discover a new node
						openSet.Add(neighbor)
					else if tentative_gScore >= gScore[neighbor]
						continue

						// This path is the best until now. Record it!
						cameFrom[neighbor] : = current
						gScore[neighbor] : = tentative_gScore
						fScore[neighbor] : = gScore[neighbor] + heuristic_cost_estimate(neighbor, goal)

						*/

