#include <iostream>
#include "graph.h"

using namespace std;

const double alpha = 0.01;

int main() {
	Neuron n1{0,0,0,true};
	n1.print();
	Neuron n2{20,35, 1, true};
	n2.print();
	
}