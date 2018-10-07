#include "graph.h"
#include <iostream>

Graph::Graph(long max_i=50) {
	std::list<Neuron *> neurons;
	size = 0;
	max_iter = max_i;
}

bool Graph::run(double inputs[]) {
	std::list<Neuron *>::iterator iter = inputNeurons.begin();
	for(int i = 0; i < inputSize; ++i) {
		
	}
	return true;
}