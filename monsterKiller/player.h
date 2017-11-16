#pragma once

class Player {
private:
	int pos;
public:
	Player(int p);
	int getPos();
	void setPos(int p);
	int moveLeft();
	int moveRight();
};



