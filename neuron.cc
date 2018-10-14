#include "neuron.h"
#include <random>
#include <iostream>
#include "math.h"

std::default_random_engine generator(time(NULL));
std::uniform_real_distribution<double> distribution(-1.0, 1.0);

// Constructor for Neuron
Neuron::Neuron(int x, int y, int i, bool input, bool output) {
	index = i;
	inputNeuron = input;
	outputNeuron = output;
	posX = x;
	posY = y;
	bias = distribution(generator);
	thres = 0;
	std::list<double> weights;
	std::list <Neuron *> connections;
}

// Prints full neuron details
void Neuron::print() {
	std::cout << "------------------------";
	std::cout << std::endl;

	std::cout << "Neuron ";
	std::cout << index;
	std::cout << ":" << std::endl;

	std::cout << "\tThreshold    : ";
	std::cout << thres << std::endl;
	std::cout << "\tposition X   : ";
	std::cout << posX << std::endl;
	std::cout << "\tposition Y   : ";
	std::cout << posY << std::endl;
	std::cout << "\tinputNeuron? : ";
	std::cout << inputNeuron << std::endl;
	std::cout << "\toutputNeuron?: ";
	std::cout << outputNeuron << std::endl;

	std::cout << "\tWeights:" << std::endl;
	int len = weights.size();
	std::list<double>::iterator iter = weights.begin();
	for(int i = 0; i < len; ++i) {
		std::cout << "\t* ";
		std::cout << i;
		std::cout << ": ";
		std::cout << (*iter) << std::endl;
		++iter;
	}

	std::cout << "\tBias: ";
	std::cout << bias << std::endl;

	std::cout << "\tConnections:" << std::endl;
	std::list<Neuron *>::iterator iter_con = connections.begin();
	for(int i = 0; i < len; ++i) {
		std::cout << "\t* ";
		std::cout << i;
		std::cout << ": Neuron ";
		std::cout << (*iter_con)->index << std::endl;
		++iter_con;
	}
}

// Establishes a link to a neuron
void Neuron::link(Neuron *n) {
	connections.push_back(n);
	weights.push_back(distribution(generator));
}

// Forward propagation of a neuron
double Neuron::forward(double input) {
	double a = sigmoid(thres);
	if(a < 0.5 && !inputNeuron){
		return 0;
	} else {
		thres = 0;
		if(connections.empty()) return a;
		int len = weights.size();

		std::list<Neuron *>::iterator iter = connections.begin();
		if(inputNeuron) {
			(*iter)->thres += input;
			for(int i = 0; i < len - 1; ++i) {
				++iter;
				(*iter)->thres += input;
			}
		} else {
			std::list<double>::iterator iterWeight = weights.begin();
			(*iter)->thres += a * (*iterWeight);
			for(int i = 0; i < len - 1; ++i) {
				++iter;
				++iterWeight;
				(*iter)->thres += a * (*iterWeight);
			}
		}
		return a;
	}
}

// Adjusts the parameters of the neuron using gradient descent
// CURRENTLY NOT USABLE
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
		std::cout << "Parameters updated" << std::endl;
	}
}