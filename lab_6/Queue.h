#pragma once
#include "Overflow.h"
#include "Underflow.h"
template <class T>
class Queue {
private:
	int front = 0;
	int back = 0;
	int items = 0;
	T* queueData[100];
	int queueSize;
public:

	
	Queue() {

	}

	
	Queue(int size){
		queueSize = size;
	} // Citation: https://stackoverflow.com/questions/751878/determine-array-size-in-constructor-initializer
	int Length() {
		return items;
	}

	template <class T>
	void Enqueue(T* data) {
		if (!isFull()) {
			queueData[back] = data;
			back = (back + 1) % queueSize;
			items++;
		}
		else {
			throw Overflow();
		}
	}

	template <class T>
	T* Dequeue() {	
		if (!isEmpty()) {
			items--;
			T* retVal = queueData[front];
			front = (front + 1) % queueSize;
			return retVal;
		}

	}

	template <class T>
	T Peek() {
		if (!isEmpty())
			return queueData[front];
		throw Underflow();
	}

	template <class T>
	void Empty() {
		for (int i = 0; i < back - 1; i++) {
			delete *queueData[i];
		}
		front = back;
		items = 0;
	}

	bool isEmpty() {
		if (items == 0)
			return true;
		return false;
	}

	bool isFull() {
		if (items == queueSize)
			return true;
		return false;
	}

};