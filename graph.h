#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include "neuron.h"
#include <vector>

using namespace std;

class Graph {
	list<Neuron *> neurons;
	list<Neuron *> inputNeurons;
	list<Neuron *> outputNeurons;
	vector<Neuron *> neuronPtr;
	long max_iter;
	int index;
public:
	Graph(long max_i=10);
	bool run(double inputs[], list<std::vector<double>> &outputMatrix);
	void add(int x, int y, bool input, bool output);
	void link(int sender, int receiver);
	void print();
};

#endif