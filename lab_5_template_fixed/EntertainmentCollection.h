#pragma once
#define MAX_BOARD_GAMES 10
#include <string>
#include "FullShelf.h"
#include "EmptyShelf.h"
#include <iostream>
using namespace std;
template <class T>
class EntertainmentCollection {
private:
	int numOfItems;
	T collection[MAX_BOARD_GAMES];

public:


	EntertainmentCollection() {
		numOfItems = 0;
	}
	void addEntertainment(T entertainment) {
		if (isFull()) throw FullShelf();
		collection[numOfItems++] = entertainment;
	}
	 T removeFromColl() {
		if (isEmpty())
			throw EmptyShelf();
		return collection[--numOfItems];
	}
	bool isEmpty() {
		if (numOfItems == 0)
			return true;
		return false;
	}

	bool isFull() {
		if (numOfItems == MAX_BOARD_GAMES)
			return true;
		return false;
	}
	void print() {
		for (int i = 0; i < getNumCollection(); i++)
			cout << (string)collection[i] << endl;
	}
	int getNumCollection() { return numOfItems; }
};
