#include "Stack.h"
#include "Underflow.h"
#include "Overflow.h"

template <class T>
Stack<T>::Stack() {
	
}

template <class T>
Stack<T>::Stack(int size) {

}

template <class T>
void Stack<T>::Push(T data) {
	if (!isFull()) {
		stackData[top] = data;
		top++;
	}
	else {
		throw Overflow();
	}
}

template <class T>
T Stack<T>::Pop() {
	if (!isEmpty())
		return stackData[--top];
	throw Underflow();
}

template <class T>
T Stack<T>::Top() {
	if (!isEmpty())
		return stackData[top];
	throw Underflow();
}

template <class T>
void Stack<T>::Empty() {

}

template <class T>
bool Stack<T>::isEmpty() {
	if (top == 0)
		return true;
	return false;
}

template <class T>
bool Stack<T>::isFull() {
	if (top == SIZE)
		return true;
	return false;
}

