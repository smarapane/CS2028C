#include<vector>
#include<random>
#include<time.h>
#include <stdlib.h>
#include "Wheel.h"
using namespace std;

Wheel::Wheel() {
	srand(time(NULL));
}

Wheel::Wheel(int max) {
	newRangeOfValues(max);
	srand(time(NULL));
}

int Wheel::spin() {
	return rangeOfVals[(double)(rand() - 1) / RAND_MAX * rangeOfVals.size()];
}
//code used to resize wheel with values
void Wheel::newRangeOfValues(int stop) {
	if (rangeOfVals.size() > stop) {
		rangeOfVals.clear();
		for (int i = 0; i < stop; ) 
			rangeOfVals.push_back(++i);
	}
	else {
		rangeOfVals.resize(stop);
	}
}
/*
void Wheel::debug () {
	for (int i = 0; i < rangeOfVals.size(); i++)
		cout << rangeOfVals[i] << endl;
}*/
