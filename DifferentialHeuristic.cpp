#include "DifferentialHeuristic.h"

DifferentialHeuristic::DifferentialHeuristic() {
	generateTable(dh);
}


float DifferentialHeuristic::h(const GridState &s, const GridState &g) {
	size_t index1 = piv1.closed.hash[s];
	size_t index2 = piv1.closed.hash[g];
	float diff1 = abs(piv1.closed.data[index1].g - piv1.closed.data[index2].g);
	
	index1 = piv2.closed.hash[s];
	index2 = piv2.closed.hash[g];
	float diff2 = abs(piv2.closed.data[index1].g - piv2.closed.data[index2].g);

	index1 = piv3.closed.hash[s];
	index2 = piv3.closed.hash[g];
	float diff3 = abs(piv3.closed.data[index1].g - piv3.closed.data[index2].g);

	index1 = piv4.closed.hash[s];
	index2 = piv4.closed.hash[g];
	float diff4 = abs(piv4.closed.data[index1].g - piv4.closed.data[index2].g);

	index1 = piv5.closed.hash[s];
	index2 = piv5.closed.hash[g];
	float diff5 = abs(piv5.closed.data[index1].g - piv5.closed.data[index2].g);

	float max1 = std::max(diff1, diff2);
	float max2 = std::max(diff3, diff4);
	float max3 = std::max(max1, max2);
	return std::max(max3, diff5);
}

void DifferentialHeuristic::generatePivots(std::vector<GridState> &pivots) {
	pivots.resize(5);
	pivots[0].x = rand() % 195;
	pivots[0].y = rand() % 195;

	pivots[1].x = rand() % 195;
	pivots[1].y = rand() % 195;

	pivots[2].x = rand() % 195;
	pivots[2].y = rand() % 195;

	pivots[3].x = rand() % 195;
	pivots[3].y = rand() % 195;

	pivots[4].x = rand() % 195;
	pivots[4].y = rand() % 195;
}

void DifferentialHeuristic::generateTable(std::vector<GridState> &dh) {
	char* map = "lak303d.map";
	Grid grid(map);
	OctileDistance od;

	std::cout << "Generating pivots...\n";
	generatePivots(pivots);

	std::cout << "Starting A* search for pivot 1...\n";
	piv1.ExhaustiveSearch(&grid, pivots[0], pivots[0], &od);

	
	std::cout << "Starting A* search for pivot 2...\n";
	piv2.ExhaustiveSearch(&grid, pivots[1], pivots[0], &od);

	
	std::cout << "Starting A* search for pivot 3...\n";
	piv3.ExhaustiveSearch(&grid, pivots[2], pivots[0], &od);

	
	std::cout << "Starting A* search for pivot 4...\n";
	piv4.ExhaustiveSearch(&grid, pivots[3], pivots[0], &od);

	
	std::cout << "Starting A* search for pivot 5...\n";
	piv5.ExhaustiveSearch(&grid, pivots[4], pivots[0], &od);

}