#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include "neuron.h"

using namespace std;

class Graph {
	list<Neuron *> neurons;
	int size;
	list<Neuron *> inputNeurons;
	int inputSize;
	long max_iter;
public:
	Graph(long max_i);
	bool run(double inputs[]);
};

#endif