#pragma once
#include <exception>
#include "DoubleLinkedList.h"
using namespace std;

class EmptyList : public exception {
public:
	
	const char* what() const throw () {
		return "List is empty";
	}
};
