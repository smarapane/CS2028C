#pragma once
#include <string>
#include "Card.h"
#define MaxSize 52
using namespace std;


class Deck {
private:
	Card *Front = nullptr, *Back = nullptr;
	int numOfCards = 0;

public:
	Deck();
	string peek();
	void loseCards();
	void addCard(string card);
	Card takeCard();
	int length() { return numOfCards; }

	bool isEmpty() { return numOfCards == 0; }
	bool isFull() { return numOfCards == MaxSize; }

};