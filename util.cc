#include "util.h"
#include <iostream>

void printOutput(std::list<std::vector<double>> &v) {
	std::list<std::vector<double>>::iterator iter = v.begin();
	int len = v.size();
	int vlen = iter->size();
	for(int i = 0; i < len; ++i) {
		for(int j = 0; j < vlen; ++j) {
			std::cout << (*iter)[j];
		}
		std::cout << std::endl;
	}
}