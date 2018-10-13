#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <list>

using namespace std;

class Neuron {
public:
	int index;
	list<double> weights;
	list<Neuron *> connections;
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