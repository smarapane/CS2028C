#pragma once
#include <exception>
#include "searchTree.h"
using namespace std;

class AlreadyExists : public exception {
public:

	const char* what() const throw () {
		return "Items already exists in tree";
	}
};