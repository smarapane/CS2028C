#pragma once
using namespace std;

class EmptyShelf : public exception {
public:

	const char* what() const throw () {
		return "Shelf is empty";
	}
}; 
