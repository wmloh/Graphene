#include "neuron.h"
#include <random>
#include <iostream>
#include "math.h"

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0, 1.0);

// Constructor for Neuron
Neuron::Neuron(int x, int y, int i, bool input) {
	index = i;
	inputNeuron = input;
	posX = x;
	posY = y;
	bias = distribution(generator);
	thres = 0;
	std::list<double> weights;
	std::list <Neuron *> connections;
}

// Prints full neuron details
void Neuron::print(int sep) {
	for(int i = 0; i < sep; ++i) {
		std::cout << "--";
	}
	std::cout << endl;

	std::cout << "Neuron ";
	std::cout << index;
	std::cout << ":" << endl;

	std::cout << "\tWeights: ";
	int len = weights.size();
	std::list<double>::iterator iter = weights.begin();
	for(int i = 0; i < len; ++i) {
		std::cout << "\t* ";
		std::cout << i;
		std::cout << ": ";
		std::cout << (*iter) << endl;
		std::advance(iter, 1);
	}
	std::cout << endl;

	std::cout << "\tBias: ";
	std::cout << bias << endl;
	std::cout << "\tThreshold: ";
	std::cout << thres << endl;
	std::cout << "\tposition X: ";
	std::cout << posX << endl;
	std::cout << "\tposition Y: ";
	std::cout << posY << endl;
	std::cout << "\tinputNeuron?: ";
	std::cout << inputNeuron << endl;
}

// Establishes a link to a neuron
void Neuron::link(Neuron *n) {
	connections.push_back(n);
	weights.push_back(distribution(generator));
}

// Increments the threshold by x
void Neuron::receiveSignal(double x) {
	thres += x;
}

// Forward propagation of a neuron
double Neuron::forward() {
	double z = sigmoid(thres);
	if(z < 0.5 || inputNeuron){
		return 0;
	} else {
		int len = weights.size();
		std::list<Neuron *>::iterator iter = connections.begin();
		for(int i = 0; i < len; ++i) {
			(*iter)->receiveSignal(z);
			std::advance(iter, 1);
		}
	}
	return z;
}

void Neuron::backward(double error, double activation, double alpha) {
	if(inputNeuron) {
		return;
	} else {
		std::list<double>::iterator iter = weights.begin();
		int len = weights.size();
		for(int i = 0; i < len; ++i) {
			(*iter) -= alpha * error * activation;
			std::advance(iter, 1);
		}
		bias -= alpha * error;
	}
}