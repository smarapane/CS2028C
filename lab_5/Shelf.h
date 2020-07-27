#pragma once
#define MAX_BOARD_GAMES 10
#include <string>
#include "BoardGame.h"
using namespace std;

class Shelf {
private:
	int numBoardGames;
    BoardGame boardGames[MAX_BOARD_GAMES];

public:
	Shelf();
	void addBoardGame(BoardGame boardGame);
	BoardGame removeBoardGame();
	int getNumBoardGames() { return numBoardGames; }
	void print();
	bool isEmpty();
	bool isFull();
};
