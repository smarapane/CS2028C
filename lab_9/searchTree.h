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
	int balance = 0;
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
		Node<T> *curr = root; // search through tree to place node
		for (; (curr->left != nullptr && wordToAdd->word < curr->word) || (curr->right != nullptr && wordToAdd->word > curr->word);) {
			if (wordToAdd->word < curr->word) curr = curr->left;
			else curr = curr->right;
		}
		//place node to the left
		if (wordToAdd->word < curr->word) {
			curr->left = wordToAdd;
			wordToAdd->parent = curr;
			Node<T>* rotater = isBalanced(root);
			if (rotater != nullptr) rotate(root);
		}
		//place node to the right
		else {
			curr->right = wordToAdd;
			wordToAdd->parent = curr;
			Node<T>* rotater = isBalanced(root); //check for balancing  
			if (rotater != nullptr) rotate(root); // rotate if off balance
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
	//help from https://stackoverflow.com/questions/4219743/balancing-an-avl-tree-c
	void rotateLeft(Node<T>* pivot) {
		//pivot node moves to the left of the left of the right child
		Node<T>* temp = pivot->left;
		pivot->left = temp->right;
		temp->parent = pivot->parent;
		temp->right = pivot;
		pivot = temp;
		pivot->right->parent = pivot;
		if(pivot->parent != nullptr) pivot->parent->right = pivot;
	}
	void rotateRight(Node<T>* pivot) {
		//pivot node moves to the left of the right of the left child
		Node<T>* temp = pivot->right;
		pivot->right = temp->left;
		temp->parent = pivot->parent;
		temp->left = pivot;
		pivot = temp;
		pivot->left->parent = pivot;
		if(pivot->parent != nullptr)pivot->parent->left = pivot;
	}
	//help from https://www.codingeek.com/data-structure/avl-tree-introduction-to-rotations-and-its-implementation/
	void rotate(Node<T>* pivot) {
		getBalanced(root);//reset the balance factor for each node in the tree
		Node<T>* useInstad;
		useInstad = findBalance(pivot); // use the correct pivot node
		if (useInstad != nullptr) pivot = useInstad;
		if (pivot->balance < 0) {
			if (getHeight(pivot->right->right) < getHeight(pivot->right->left)) {
				rotateLeft(pivot->right);//left right rotate
				rotateRight(pivot);
				if (pivot == root) root = pivot->parent;
				return;
			}
			else {
				rotateRight(pivot);//single right rotate
				if (pivot == root) root = pivot->parent;
				
				return;
			}
		}
		else {
			if (getHeight(pivot->left->left) < getHeight(pivot->left->right)) {
				rotateRight(pivot->left);//right left rotate
				rotateLeft(pivot);
				pivot->left->parent = pivot;
				if (pivot == root) root = pivot->parent;
				return;
			}
			else {
				rotateLeft(pivot);//single left rotate
				if (pivot == root) root = pivot->parent;
				return;
			}
		}
	}

	int getHeight(Node<T>* temp) {
		//taken from class notes
		if (temp == nullptr) return 0;
		int leftH = getHeight(temp->left);
		int rightH = getHeight(temp->right);
		if (rightH > leftH) return 1 + rightH;
		else return 1 + leftH;
	}
	Node<T>* isBalanced(Node<T>* root) {
		//determine if given node is balanced root
		if (root == nullptr) return nullptr;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		int diffHeight = left - right;
		root->balance = diffHeight;
		if ((diffHeight > 1 || diffHeight < -1) && isBalanced(root->right) == nullptr && isBalanced(root->left) == nullptr) return root;
		else return nullptr;
	}
	void getBalanced(Node<T>* root) {
		//get the balance factor for each node
		if (root == nullptr) return;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		int diffHeight = left - right;
		root->balance = diffHeight;
		getBalanced(root->left);
		getBalanced(root->right);
	}
	Node<T>* findBalance(Node<T>* val) {
		//get the correct pivot node
		if (val == nullptr) return nullptr;
		
		if (val->balance > 1 || val->balance < -1 && val != root ) 
			return val;
		Node<T>* retVal = findBalance(val->right);
		if(retVal == nullptr) retVal = findBalance(val->left);
		else return retVal;
		
	}
	void getAllAscending(Node<T>* curr = root) {
		if (curr == nullptr) return;
		getAllAscending(curr->left);
		ascendSort[pos++] = curr;
		getAllAscending(curr->right);
		ascendSort[pos++] = curr;
	}

	void EmptyTree(Node<T>* parent = root) {							
		if (parent->left != nullptr) EmptyTree(parent->left);
		if (parent->right != nullptr) EmptyTree(parent->right);
		delete parent;
	}
};