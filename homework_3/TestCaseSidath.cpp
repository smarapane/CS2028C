#include "deck.h"
#include "Card.h"
#include "sidePile.h"

bool testPeek() {
	Deck deck;

	deck.addCard("Test1");			//peek should return this
	deck.addCard("Test2");
	deck.addCard("Test3");

	return deck.peek() == "Test1";
}

bool testTakeCard() {
	Card card1("Test");
	sidePile sidePile;
	sidePile.addCard(card1);
	return sidePile.takeCard().getData() == "Test";
}
