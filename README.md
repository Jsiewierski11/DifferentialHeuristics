
***Task:***
In this assignment you will implement differential heuristics. In your heuristic you will use an A* search to find the distance to every state from a given pivot. When you need to compute a heuristic between two states, you will look up each of these states in the A* closed list and subtract their g-costs to get the heuristic. (You should take the max of this and octile distance to get the final heuristic.)
You should implement the random placement strategy. In the random strategy you will select 5 random pivots (for the differential heuristic) and take the max of these heuristics with octile distance.

***Testing:***
Test your program on the map and benchmark problems for the lak303d map from the movingai repository.  (http://movingai.com/benchmarks/dao/)
 (Links to an external site.)
Show the number of node expansions required to solve the test problems with (1) octile distance and (2) randomly placed DH pivots.
