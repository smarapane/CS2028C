#include "HashTable.h"
#include "DNE.h"
#include <iostream>

using namespace std;

HashTable::HashTable(){}

HashTable::~HashTable(){}

int HashTable::hashingFunction(int val){
	return (val % 500);
}
int HashTable::insert(int newInsert) {
	int pos = hashingFunction(newInsert);
	int collisionCount = 1;
	while(table[pos] != 0) {
		pos++;
		collisionCount++;
	}
	table[pos] = newInsert;
	return collisionCount;
}
int HashTable::find(int val) {
	int pos = hashingFunction(val);
	int collisionCount = 1;
	while (table[pos] != val) {
		if (pos == (MAX - 1)){
			return pos;
		}
		pos++;
	}
	while (table[++pos] == val) {
		collisionCount++;
	}

	return collisionCount;
}
int HashTable::remove(int val) {
	int pos = hashingFunction(val);
	int collisionCount = 1;
	while (table[pos] != val) {
		if (pos == (MAX - 1)) {
			return pos;
		}
		pos++;
		collisionCount++;
	}
	table[pos] = 0;
	return collisionCount;
}
void HashTable::print(){
	for (int i = 0; i < MAX; i++) {
		if (table[i] == 0) cout << "|Empty|";
		else cout << "|" << table[i] << "|";
		if (i % 25 == 0 && i != 0) cout << "\n";
	}
}