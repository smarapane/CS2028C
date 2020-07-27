#pragma once
#include <string>
#define MAX 400
using namespace std;

template <typename T>
class Node {
  public:
	Node(){}
	Node(T newVal) {
		word = newVal;
		count = 1;
		left = right = parent = nullptr;
	}
	string word;
	int count;
	Node* left, *right, *parent;
	bool operator<(Node<string> compWord) {
	if(0 < word.compare(compWord.word)) return true;
	return false;
	}
	bool operator>(Node<string> compWord) {
		if (0 < compWord.word.compare(this->word)) return true;
		return false;
	}
};
template <typename T>
class searchTree {
private:
	Node<T> *root = nullptr;
	int size = 0;
	int pos = 0;
	Node<T> ascendSort[MAX];
	Node<T> descendSort[MAX];
public:
	searchTree(){}
	void addNode(T word) {
		Node<T>* wordToAdd = new Node<T>(word);
		if (root == nullptr) {
			root = wordToAdd;
			size++;
			return;
		}
		Node<T> *curr = root;
		for (; (curr->left != nullptr && wordToAdd->word < curr->word) || (curr->right != nullptr && wordToAdd->word > curr->word);) {
			if (wordToAdd->word < curr->word) curr = curr->left;
			else curr = curr->right;
		}

		if (wordToAdd->word < curr->word) {
			curr->left = wordToAdd;
			wordToAdd->parent = curr;
			if (!isBalanced(root)) rotate(wordToAdd, 1);
		}
		else {
			curr->right = wordToAdd;
			wordToAdd->parent = curr;
			if (!isBalanced(root)) rotate(wordToAdd, 0);
		}
 		size++;
	}
	Node<T>* Find(T key){
		if (root == nullptr) return nullptr;
		if (root->word == key) return root;
		Node<T>* curr = root;
		for (; curr->left != nullptr && key < curr->word || curr->right != nullptr && key > curr->word;) {
			if (key < curr->word) curr = curr->left;
			else curr = curr->right;
		}
		if (curr->word == key) return curr;
		else return nullptr;
	}
	int getSize() { return size; }

	Node<T>* removeNode(T key) {
		Node<T>* remove = Find(key);
		if (remove->left == nullptr && remove->right == nullptr) {
			remove = remove->parent;
			Node<T>* retVal;
			if (remove->word > key) {
				*retVal = remove->left;
				delete remove->left;
				remove->left = nullptr;
			}
			else {
				retVal = remove->right;
				delete remove->right;
				remove->right = nullptr;
			}
		}
		//one child
		if (remove->left != nullptr && remove->right == nullptr
			|| remove->left == nullptr && remove->right != nullptr) {
			remove = remove->parent;
			if (remove->left->word == key) {
				Node<T>* delNode = remove->left;
				if (delNode->left != nullptr) remove->left = delNode->left;
				else remove->left = delNode->right;
				delete delNode;
			}
			else {
				Node<T>* delNode = remove->right;
				if (delNode->right != nullptr) remove->left = delNode->left;
				else remove->right = delNode->right;
				delete delNode;
			}
		}
		//two child
		else {
			remove = remove->parent; 
			Node<T>* rep;
			if (remove->word < key) {
				rep = remove->left;
				rep = rep->right;
				while (rep->left != nullptr)
					rep = rep->left;
				rep = new Node<T>(removeNode(rep->word));
				rep->left = remove->right->left;
				rep->right = remove->right->right;
				delete remove->right;
				remove->right = rep;
			}
			else {
				rep = remove->right;
				rep = rep->left;
				while (rep->right != nullptr)
					rep = rep->right;
				rep = new Node<T>(removeNode(rep->word));
				rep->right = remove->left->right;
				rep->left = remove->left->left;
				delete remove->left;
				remove->left = rep;
			}
		}
	}
	void rotate(Node<T>* pivot, bool leftOrRight){
		if (leftOrRight == true) {
			if (pivot->parent->right == nullptr) {
				Node<T>* temp = new Node<T>(pivot->parent->word);
				temp->parent = pivot->parent;
				pivot->parent->parent->right = pivot;
				pivot->parent = pivot->parent->parent;
				pivot->right = temp;
				pivot->right->parent = pivot;
				pivot->left = nullptr;
				pivot = pivot->right;
			}
			pivot->parent->left = pivot->parent->parent;
			pivot->parent->parent = nullptr;
			pivot->parent->left->left = nullptr;
			pivot->parent->left->right = nullptr;
			pivot->parent->parent = pivot->parent;
		}
		else {
			pivot->parent->parent->right = pivot;
			pivot->parent = pivot->right;
			pivot->right = pivot->parent;
		}
	}

	int getHeight(Node<T>* temp) {
		if (temp == nullptr) return 0;
		int leftH = getHeight(temp->left);
		int rightH = getHeight(temp->right);
		if (rightH > leftH) return 1 + rightH;
		else return 1 + leftH;
	}
	bool isBalanced(Node<T>* root) {
		if (root == nullptr) return 1;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		int diffHeight = abs(left - right);
		if (diffHeight > 1 && isBalanced(root->right) && isBalanced(root->left)) return false;
		else return true;
	}
	void getAllAscending(Node<T>* curr = root) {
		if (curr == nullptr) return;
		getAllAscending(curr->left);
		ascendSort[pos++] = curr;
		getAllAscending(curr->right);
		ascendSort[pos++] = curr;
	}


	void EmptyTree(Node<T>* parent = root) {								//double check this
		if (parent->left != nullptr) EmptyTree(parent->left);
		if (parent->right != nullptr) EmptyTree(parent->right);
		delete parent;
	}

	
};