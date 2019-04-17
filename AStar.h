//
//  AStar.h
//  HW5
//
//  Created by Nathan Sturtevant on 5/11/18.
//  Copyright © 2018 NS Software. All rights reserved.
//

#ifndef AStar_h
#define AStar_h

#include <vector>
#include "AStarOpenList.h"

template <class environment, class state, class action>
class AStar {
public:
	void GetPath(environment *env, state start, state goal, Heuristic<state> *h, std::vector<state> &path);
	void ExhaustiveSearch(environment *env, state start, state goal, Heuristic<state> *h);
	uint64_t GetNodesExpanded();
	AStarOpenList<state> closed;
private:
	uint64_t expansions;
	AStarOpenList<state> q;
	std::vector<action> acts;
};


template <class environment, class state, class action>
void AStar<environment, state, action>::GetPath(environment *env, state start, state goal,
	Heuristic<state> *h, std::vector<state> &path)
{
	expansions = 0;
	path.resize(0);
	q.Reset();
	q.Add(start, 0, h->h(start, goal));
	while (!q.Empty())
	{
		AStarData<state> next = q.GetNext();
		//std::cout << "Expanding " << next.state << "\n";
		if (next.state == goal)
		{
			q.GetPath(next.state, path);
			printf("Goal found at cost %d; %llu total expansions\n", (int)path.size(), expansions);
			return;
		}
		env->GetOperators(next.state, acts);

		for (auto op : acts)
		{
			state tmp = next.state;
			env->ApplyOperator(tmp, op);
			//std::cout << "**Sucessor " << tmp << "\n";
			q.Add(tmp, next.g + env->GetCost(op), h->h(tmp, goal), next.state);
			expansions++;
		}
	}
}

template <class environment, class state, class action>
uint64_t AStar<environment, state, action>::GetNodesExpanded()
{
	return expansions;
}


template <class environment, class state, class action>
void AStar<environment, state, action>::ExhaustiveSearch(environment *env, state start, state goal,	Heuristic<state> *h)
{
	q.Reset();
	q.Add(start, 0, h->h(start, goal));
	while (!q.Empty())
	{
		AStarData<state> next = q.GetNext();
		closed.Add(next.state, next.g, next.h);

		//std::cout << "Expanding " << next.state << "\n";
		//Exhaustive Search does not need goal check
		/*
		if (next.state == goal)
		{
			q.GetPath(next.state, path);
			return;
		}
		*/

		env->GetOperators(next.state, acts);

		for (auto op : acts)
		{
			state tmp = next.state;
			env->ApplyOperator(tmp, op);
			//std::cout << "**Sucessor " << tmp << "\n";
			q.Add(tmp, next.g + env->GetCost(op), h->h(tmp, goal), next.state);
		}
	}
}


#endif /* AStar_h */
