#pragma once
class Node {
public:
	Node() {
		num = 0;
	}
	Node(int newVal) {
		num = newVal;
	}
	int num;
	Node * left = nullptr, *right = nullptr;
};
class searchTree {
private:
	Node *root = nullptr;
	int size = 0;
public:
	searchTree() {}
	int addNode(int num) {
		int searchCount = 1;
		Node* numToAdd = new Node(num);
		if (root == nullptr) {
			root = numToAdd;
			size++;
			return searchCount;
		}
		Node *curr = root;
		for (; (curr->left != nullptr && numToAdd->num < curr->num) || (curr->right != nullptr && numToAdd->num > curr->num);) {
			if (numToAdd->num < curr->num) curr = curr->left;
			else curr = curr->right;
			searchCount++;
		}

		if (numToAdd->num < curr->num) {
			curr->left = numToAdd;
		}
		else {
			curr->right = numToAdd;
		}
		size++;
		return searchCount;
	}
	int Find(int key) {
		int searchCount = 1;
		if (root == nullptr) return 0;
		if (root->num == key) return searchCount;
		Node* curr = root;
		for (; curr->left != nullptr && key < curr->num || curr->right != nullptr && key > curr->num;) {
			if (key < curr->num) curr = curr->left;
			else curr = curr->right;
			searchCount++;
		}
		if (curr->num == key) return searchCount;
		else return 0;
	}
	int removeNode(int key) {
		int searchCount = 1;
		if (root == nullptr) return 0;
		if (root->num == key) return searchCount;
		Node* curr = root;
		for (; curr->left != nullptr && key < curr->num || curr->right != nullptr && key > curr->num;) {
			if (key < curr->num)
				curr = curr->left;
			else curr = curr->right;
			searchCount++;
		}
		if (curr->num == key) {
			Node* temp = root;
			for (; temp->left != nullptr && key != temp->left->num || temp->right != nullptr && key != temp->right->num;) {
				if (key < temp->num)
					temp = temp->left;
				else temp = temp->right;
			}
			
			if (curr->left == nullptr && curr->right == nullptr) {
				delete curr;
				return searchCount;
			}
			//one child
			if (curr->left != nullptr && curr->right == nullptr
				|| curr->left == nullptr && curr->right != nullptr) {
				if (temp->left != nullptr && temp->left->num == key) {
					if (curr->left != nullptr) temp->left = curr->left;
					else temp->left = curr->right;
					delete curr;
				}
				else {
					if (curr->left != nullptr) temp->right = curr->left;
					else temp->right = curr->right;
					delete curr;
				}
			}
			//two child
			else {
				Node* rep = nullptr;
				if (temp->left->num == key) {
					Node* remove = temp->left;
					rep = remove->left;
					rep = rep->right;
					while (rep->left != nullptr)
						rep = rep->left;
					rep = new Node (removeNode(rep->num));
					rep->left = remove->right->left;
					rep->right = remove->right->right;
					delete remove->right;
					remove->right = rep;
				}
				else {
					Node* remove = temp->right;
					rep = rep->left;
					while (rep->right != nullptr)
						rep = rep->right;
					rep = new Node (removeNode(rep->num));
					rep->right = remove->left->right;
					rep->left = remove->left->left;
					delete remove->left;
					remove->left = rep;
				}
			}
			return searchCount;
		}
	}
};