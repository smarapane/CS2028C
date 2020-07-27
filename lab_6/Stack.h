#pragma once
#include "Underflow.h"
#include "Overflow.h"
template <class T>
class Stack {
private:
	T* stackData[100];
	int top = 0;
	int stackSize;

public:

	Stack() {}

	Stack(int size) {
		stackSize = size;

	} // Citation (NO): https://stackoverflow.com/questions/751878/determine-array-size-in-constructor-initializer
	template <class T>
	void Push(T* data) {
		if (!isFull()) {
			stackData[top] = data;
			top++;
		}
		else {
			//throw Overflow();
		}
	}

	template <class T>
	T* Pop() {
		if (!isEmpty()) {
			--top;
			return stackData[top];
		}
		throw Underflow();
	}

	template <class T>
	T Top() {
		if (!isEmpty())
			return *stackData[top];
		throw Underflow();
	}

	void Empty() {
		for (int i = 0; i < top - 1; i++) {
			delete stackData[i];
		}
		top = 0;
	}

	bool isEmpty() {
		if (top == 0)
			return true;
		return false;
	}

	bool isFull() {
		if (top == stackSize)
			return true;
		return false;
	}
	
	int Length() { return top; }
};


