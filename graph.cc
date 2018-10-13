#include "graph.h"
#include <iostream>

Graph::Graph(long max_i) {
	std::list<Neuron *> neurons;
	list<Neuron *> inputNeurons;
	list<Neuron *> outputNeurons;
	vector<Neuron *> neuronPtr;
	max_iter = max_i;
	index = 0;
}

bool Graph::run(double inputs[], std::list<std::vector<double>> &outputMatrix) {
	std::list<Neuron *>::iterator iterIn = inputNeurons.begin();
	std::list<Neuron *>::iterator iter = neurons.begin();
	std::list<Neuron *>::iterator iterOut = outputNeurons.begin();

	int ilen = inputNeurons.size();
	int nlen = neurons.size();
	int olen = outputNeurons.size();

	for(int timestep=0; timestep < max_iter; ++timestep) {
		
		for(int i = 0; i < ilen; ++i) {
			(*iterIn)->forward(inputs[i]);
			//std::advance(iterIn, 1);
		}
		
		for(int i = 0; i < nlen; ++i) {
			(*iter)->forward();
			//std::advance(iter, 1);
		}
		
		std::vector<double> v;
		for(int i = 0; i < olen; ++i) {
			v.push_back((*iterOut)->forward());
			std::advance(iterOut, 1);
		}
		outputMatrix.push_back(v);
	}
	return true;
}

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

void Graph::link(int sender, int receiver) {
	neuronPtr[sender]->link(neuronPtr[receiver]);
}

void Graph::print() {
	int len = neuronPtr.size();
	for(int i = 0; i < len; ++i) {
		neuronPtr[i]->print();
	}
}