#pragma once
#define MAX 500
class HashTable {
private:
	int table[MAX] = { 0 };
	int hashingFunction(int val);
public:
	HashTable();
	~HashTable();
	int insert(int newInsert);
	int find(int val);
	int remove(int val);
	void print();
};