#include <iostream>
#include <fstream>
#include "searchTree.h"
#include <string>
using namespace std; 
int main(){
  ifstream info;
  searchTree<string>* treeWithWords = new searchTree<string>();
  info.open("testText.txt");
  string dataRead;
  while (info >> dataRead) {
	  Node<string>* temp = treeWithWords->Find(dataRead);
	  if (temp == nullptr) {
		  treeWithWords->addNode(dataRead);
	  }
	  else temp->count++;      
  }

  return 0;
}