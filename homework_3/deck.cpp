#include "deck.h"
#include "Overflow.h"
#include "Underflow.h"
#include <string>
using namespace std;

Deck::Deck() {

}
void Deck::addCard(string newCard) {
	if (isFull()) throw Overflow();				

	if(Front == nullptr){						
		Front = new Card(newCard);
		Back = Front;
	}

	else {
		Back->next = new Card(newCard);			
		Back = Back->next;						
	}

	numOfCards++;

}

string Deck::peek() {
	if (isEmpty()) throw Underflow();
	return Front->getData();							
}

void Deck::loseCards() {		
	Card *temp = Front;
	Front = Front->next;
	delete temp;
}
Card Deck::takeCard() {
	Card temp = *Front;
	Front = Front->next;
	temp.next = nullptr;
	numOfCards--;
	return temp;
}