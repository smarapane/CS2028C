#pragma once
using namespace std;

class FullShelf : public exception {
public:

    const char* what() const throw (){
        return "Shelf is full";
    }
};

