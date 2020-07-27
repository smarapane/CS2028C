#include "sidePile.h"
#include "Overflow.h"
#include "Underflow.h"
#include <string>
using namespace std;

sidePile::sidePile() {
	
}

void sidePile::addCard(Card card) {
	if (isFull()) throw Overflow();
	deckSize[size] = card;
	size++;
}

Card sidePile::takeCard() {
	if (isEmpty()) throw Underflow();
	return deckSize[--size];			
}

