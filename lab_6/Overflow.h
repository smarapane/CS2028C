#pragma once
#include "Stack.h"
#include "Queue.h"
using namespace std;

class Overflow : public exception {
public:

	const char* what() const throw () {
		return "Structure is full";
	}
};