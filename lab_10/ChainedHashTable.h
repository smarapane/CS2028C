#pragma once
#include <string>
#include "LinkedList.h"
#include <iostream>
#define MAX 20
using namespace std;
template <typename T>
class ChainedHashTable {
private:
	DoubledLinkedList<T>* table[MAX] = { nullptr };
	int numOfItems = 0;
	int comparisons = 0;
	//hashing algorithm: takes ascii values, sums them together, then takes modulo Max of that sum
	int hashingFunction(string val) {
		string newVal = val;
		int sum = 0;
		for (int i = 0; i < newVal.size(); i++)
			sum += int(newVal[i]);
		return sum % MAX;
	}
public:
	ChainedHashTable() {
	
	}
	void insert(T* newInsert) {
		int pos = hashingFunction(*newInsert);	 //convert item object to string and hash.
		DoubledLinkedList<T>* newSpot = new DoubledLinkedList<T>();	//initialize a new linked list to insert into table
		newSpot->AddItem(*newInsert);	// add item to insert into linked list
		if (table[pos] == nullptr) table[pos] = newSpot;
		else {
			DoubledLinkedList<T>* newSpot = table[pos];	//if there is a collision add item to already existing linked list
			newSpot->AddItem(*newInsert);
		}
		numOfItems++;
	}
	T* find(T* val) {
		int pos = hashingFunction(*val);
		DoubledLinkedList<T>* newSpot = table[pos];
		comparisons += newSpot->IsInList(val);
		if (comparisons == 0)  return nullptr;
		return val;
	}
	T* remove(T* val) {
		int pos = hashingFunction(*val);
		DoubledLinkedList<T>* newSpot = table[pos];
		if (newSpot->IsInList(val) == 0)  return nullptr;
		else newSpot->GetItem(*val);
		numOfItems--;
		return val;
	}
	int getLength() { return numOfItems; }
	int getComps() { return comparisons; }
	void print() {
		for (int i = 0; i < MAX; i++) {
			DoubledLinkedList<T>* newSpot = table[i];
			cout << "| ";
			if (newSpot == nullptr){
				cout << "|EMPTY|";
			
			}
			else {
				for (int j = 0; j < newSpot->Size(); j++) {
					T print = newSpot->SeeAt(j);
					cout << "(" << print.getSku() << ")->";
				}
			}
			cout << " |";
			if (i % 10 == 0 && i != 0) cout << "\n";
		}
		cout << endl;
	}
};