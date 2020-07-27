#include "Shelf.h"
#include "BoardGame.h"
#include "EmptyShelf.h"
#include "FullShelf.h"
#include <iostream>
using namespace std;

Shelf::Shelf() {
	numBoardGames = 0;
}

void Shelf::addBoardGame(BoardGame boardGame) {
	if (isFull())
		throw FullShelf();
    boardGames[numBoardGames++] = boardGame;
}

BoardGame Shelf::removeBoardGame() {
	if (isEmpty())
		throw EmptyShelf();
	return boardGames[--numBoardGames];
}

bool Shelf::isEmpty() {
	if (numBoardGames == 0)
		return true;
	return false;
}

bool Shelf::isFull() {
	if (numBoardGames == MAX_BOARD_GAMES)
		return true;
	return false;
}

void Shelf::print() {
	for (int i = 0; i < getNumBoardGames(); i++)
		cout << boardGames[i].getName() << endl;
}