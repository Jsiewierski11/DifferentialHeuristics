#ifndef DifferentialHeuristic_h
#define DifferentialHeuristic_h

#include "Heuristic.h"
#include "Grid.h"
#include "AStar.h"
#include "AStarOpenList.h"
#include "OctileDistance.h"
#include <vector>
#include <random>
#include <iostream>
#include <math.h>
#include <algorithm>

class DifferentialHeuristic : public Heuristic<GridState> {
public:
	DifferentialHeuristic();
	float h(const GridState &s, const GridState &);
	AStar<Grid, GridState, GridAction> piv1;
	AStar<Grid, GridState, GridAction> piv2;
	AStar<Grid, GridState, GridAction> piv3;
	AStar<Grid, GridState, GridAction> piv4;
	AStar<Grid, GridState, GridAction> piv5;
private:
	void generatePivots(std::vector<GridState> &pivots);
	void generateTable(std::vector<GridState> &dh);
	std::vector<GridState> dh;
	std::vector<GridState> pivots;
};


#endif
