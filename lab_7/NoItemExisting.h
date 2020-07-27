#pragma once
#include <exception>
using namespace std;

class NoItemExisting : public exception {
public:

	const char* what() const throw () {
		return "Item does not exist.";
	}
};