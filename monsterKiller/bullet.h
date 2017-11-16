#pragma once

class Bullet {
private:
	int pos;
	int direction;
public:
	Bullet(int p, int d);
	int getPos();
	void setPos(int p);
	int getDirection();
	void setDirection(int d);
	int move();
};


