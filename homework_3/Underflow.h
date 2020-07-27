#pragma once
#include "Card.h"
#include "deck.h"
using namespace std;

class Underflow : public exception {
public:

	const char* what() const throw () {
		return "Structure is empty";
	}
};