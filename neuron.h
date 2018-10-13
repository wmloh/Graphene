#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <list>

using namespace std;

class Neuron {
	int index;
	list<double> weights;
	double bias;
	double thres;
	list<Neuron *> connections;
	int posX;
	int posY;
	bool inputNeuron;
	bool outputNeuron;
public:
	Neuron(int x, int y, int i, bool input, bool output);
	void print(int sep=12);
	void link(Neuron *n);
	double forward(double input=0);
	void backward(double error, double activation, double alpha);
};

#endif