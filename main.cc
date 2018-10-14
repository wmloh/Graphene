#include "graph.h"
#include "util.h"

const double alpha = 0.1;

int main() {
	srand(time(NULL));

	Graph g{2};
	int n1 = g.add(0, 0, true, false);
	int n2 = g.add(20, 35, false, false);
	int n3 = g.add(50, 50, false, true);
	int n4 = g.add(60, 60, false, true);
	
	g.link(n1, n2);
	g.link(n2, n3);
	g.link(n1, n4);

	std::list<std::vector<double>> v;
	double input[1] = {5};

	g.run(input, v);

	printOutput(v);
	g.print();
}