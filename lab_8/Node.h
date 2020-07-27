#pragma once
template <class T>
struct Node {
	Node<T>() {};
	Node<T> * next = nullptr;
	Node<T> * prev = nullptr;
	T data;
};
