#include "Queue.h"
#include "Overflow.h"
#include "Underflow.h"

template <class T>
Queue<T>::Queue() {

}

template <class T>
Queue<T>::Queue(int size) {

}

template <class T>
void Queue<T>::Enqueue(T data) {
	if (!isFull()) {
		queueData[back] = data;
		back = (back + 1) % SIZE;
		items++;
	}
	else {
		throw Overflow();
	}
}

template <class T>
T Queue<T>::Dequeue() {
	if (!isEmpty()) {
		items--;
		front = (front + 1) % SIZE;
		return queueData[front];			
	}

}

template <class T>
T Queue<T>::Peek() {
	if (!isEmpty())
		return queueData[front];
	throw Underflow();
}

template <class T>
void Queue<T>::Empty() {

}

template <class T>
bool Queue<T>::isEmpty() {
	if (items == 0)
		return true;
	return false;
}

template <class T>
bool Queue<T>::isFull() {
	if (items == SIZE)
		return true;
	return false;
}

