#pragma once
#include <string>
using namespace std;
class Card {
public:
	Card() {

	}
	Card(string card) {
		data = card;
	}

	Card *next = nullptr;
	string getData() { return data; }

private:
	string data;
};
