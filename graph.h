#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include "neuron.h"
#include <vector>

class Graph {
public:
	std::list<Neuron *> neurons;
	std::list<Neuron *> inputNeurons;
	std::list<Neuron *> outputNeurons;
	std::vector<Neuron *> neuronPtr;
	long max_iter;
	int index;

	Graph(long max_i=10);
	bool run(double inputs[], std::list<std::vector<double>> &outputMatrix);
	int add(int x, int y, bool input, bool output);
	void link(int sender, int receiver);
	void print();
};

#endif