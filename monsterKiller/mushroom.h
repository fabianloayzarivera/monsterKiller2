#pragma once

class Mushroom {
private:
	int pos;
	int bonusPoints;
public:
	Mushroom(int p, int bP);
	int getPos();
	void setPos(int p);
	int getBonusPoints();
	void setBonusPoints(int p);
	
};