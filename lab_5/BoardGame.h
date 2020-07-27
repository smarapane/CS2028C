#pragma once
#include "Shelf.h"
#include <string>
using namespace std;

class BoardGame {

public:
	BoardGame(string name) { nameOfBoardGame = name; }
	BoardGame() { nameOfBoardGame = ""; }
	void setName(string name) { nameOfBoardGame = name; }
	string getName() { return nameOfBoardGame; }

private:
	string nameOfBoardGame = "";
};