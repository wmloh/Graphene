#include "graph.h"
#include "util.h"

const double alpha = 0.1;

int main() {
	srand(time(NULL));

	Graph g{2};
	g.add(0, 0, true, false);
	g.add(20, 35, false, false);
	g.add(50, 50, false, true);

	g.link(0, 1);
	g.link(1, 2);

	std::list<std::vector<double>> v;
	double input[1] = {5};

	g.run(input, v);

	printOutput(v);
	//g.print();
}