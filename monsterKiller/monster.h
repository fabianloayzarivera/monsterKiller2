#pragma once

class Monster {
private:
	int pos;
	int direction;
public:
	Monster(int p, int d);
	int getPos();
	void setPos(int p);
	int getDirection();
	void setDirection(int d);
	int move();
};