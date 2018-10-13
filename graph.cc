#include "graph.h"
#include <iostream>

// Constructor for Graph
Graph::Graph(long max_i) {
	std::list<Neuron *> neurons;
	std::list<Neuron *> inputNeurons;
	std::list<Neuron *> outputNeurons;
	std::vector<Neuron *> neuronPtr;
	max_iter = max_i;
	index = 0;
}

// Forward propagates all neurons in the graph
bool Graph::run(double inputs[], std::list<std::vector<double>> &outputMatrix) {
	std::list<Neuron *>::iterator iterIn = inputNeurons.begin();
	std::list<Neuron *>::iterator iter = neurons.begin();
	std::list<Neuron *>::iterator iterOut = outputNeurons.begin();

	int ilen = inputNeurons.size();
	int nlen = neurons.size();
	int olen = outputNeurons.size();

	for(int timestep=0; timestep < max_iter; ++timestep) {
		
		(*iterIn)->forward(inputs[0]);
		for(int i = 0; i < ilen-1; ++i) {
			++iterIn;
			(*iterIn)->forward(inputs[i+1]);
		}
		
		(*iter)->forward();
		for(int i = 0; i < nlen-1; ++i) {
			++iter;
			(*iter)->forward();
		}
		
		std::vector<double> v;
		v.push_back((*iterOut)->forward());
		for(int i = 0; i < olen-1; ++i) {
			++iterOut;
			v.push_back((*iterOut)->forward());
		}
		outputMatrix.push_back(v);
	}
	return true;
}

// Adds a Neuron into Graph
void Graph::add(int x, int y, bool input, bool output) {
	Neuron *n = new Neuron(x, y, index, input, output);
	neuronPtr.push_back(n);
	if(input) {
		inputNeurons.push_back(n);
	} else if (output) {
		outputNeurons.push_back(n);
	} else {
		neurons.push_back(n);
	}
	++index;
}

// Links two Neuron signal transmission
void Graph::link(int sender, int receiver) {
	neuronPtr[sender]->link(neuronPtr[receiver]);
}

// Prints full details of all Neurons in the Graph
void Graph::print() {
	int len = neuronPtr.size();
	for(int i = 0; i < len; ++i) {
		neuronPtr[i]->print();
	}
}