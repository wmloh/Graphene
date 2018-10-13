#include "graph.h"
#include <cmath>
#include "util.h"

const double alpha = 100;

int main() {
	srand(time(NULL));

	Graph g;
	g.add(0, 0, true, false);
	g.add(20, 35, false, false);
	g.add(50, 50, false, true);

	std::cout << "1" << endl;

	std::list<std::vector<double>> v;
	double input[1] = {5};

	std::cout << "2" << endl;

	g.run(input, v);

	std::cout << "3" << endl;

	printOutput(v);
	g.print();
}