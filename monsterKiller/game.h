#pragma once

#include <list>
#include <iostream>
#include "player.h"
#include "bullet.h"

class Game {
private:
	int worldSize;
	int bulletAmount;
	char playerGraphic;
	char bulletGraphicLeft;
	char bulletGraphicRight;
	char floorGraphic;
	Player *player;
	std::list<Bullet *>listBullets;

public:
	Game(int wS, char fG, char pG, char bgL, char bgR);
	int getWorldSize();
	char getPlayerGraphic();
	char getFloorGraphic();
	void setWorldSize(int w);
	void setPlayerGraphic(char g);
	void setFloorGraphic(char g);
	void paintWorld();
	void movePlayerLeft();
	void movePlayerRight();
	void firePlayerLeft();
	void firePlayerRight();
	void createFrame();

};



