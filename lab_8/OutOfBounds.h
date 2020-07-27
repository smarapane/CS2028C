#pragma once
#include <exception> 
using namespace std;

class OutOfBounds : public exception {
public:

	const char* what() const throw () {
		return "Out of Bounds";
	}
};