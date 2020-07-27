#pragma once
#include <exception>
#include "HashTable.h"
using namespace std;

class DNE : public exception {
public:

	const char* what() const throw () {
		return "Item does not exist in table";
	}
};