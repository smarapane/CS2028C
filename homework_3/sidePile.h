#pragma once
#define MaxSizeSide 5
#include <string>
#include "Card.h"
using namespace std;

class sidePile{
private:
	Card deckSize[MaxSizeSide];
	int size = 0;
public:
	sidePile();
	Card takeCard();
	void addCard(Card card);
	int getSize() { return size; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MaxSizeSide; }

};
