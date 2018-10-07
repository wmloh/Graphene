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
public:
	Neuron(int x, int y, int i, bool input);
	void print(int sep=12);
	void link(Neuron *n);
	void receiveSignal(double x);
	double forward();
	void backward(double error, double activation, double alpha);
};

#endif