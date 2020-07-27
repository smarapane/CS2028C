#pragma once
#include<random>
#include<time.h>
#include "Wheel.h"

class Player {
private:
	double playerMoney;
	int numberOutput;
	Wheel playerWheel;

public:
	Player();
	Player(double money, Wheel wheel);
	double getPlayerMoney() { return playerMoney; }
	void setPlayerMoney(double money) { playerMoney = money; }
	void setPlayerWheel(Wheel wheel) { playerWheel = wheel; }
	void setNumberOutput() { numberOutput = playerWheel.spin(); }
	int getNumberOutput() { return numberOutput; }
};