#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <list>

class Neuron {
public:
	int index;
	std::list<double> weights;
	std::list<Neuron *> connections;
	double bias;
	double thres;
	int posX;
	int posY;
	bool inputNeuron;
	bool outputNeuron;

	Neuron(int x, int y, int i, bool input, bool output);
	void print();
	void link(Neuron *n);
	double forward(double input=0);
	void backward(double error, double activation, double alpha);
};

#endif