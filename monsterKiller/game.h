#pragma once

#include <list>
#include <iostream>
#include "player.h"
#include "bullet.h"
#include "monster.h"
#include "mushroom.h"
#include "weatherManager.h"

const int mushroomBonusPoints = 10;
const int monsterKillPoints = 1;
const int weatherRainLevel = 3;

class Game {
private:
	int worldSize;
	int bulletAmount;
	int monsterAmount;
	int mushroomAmount;
	int lives;
	int score;
	char playerGraphic;
	char bulletGraphicLeft;
	char bulletGraphicRight;
	char floorGraphic;
	char monsterGraphic;
	char mushroomGraphic;
	Player *player;
	Mushroom *mushroom;
	WeatherManager *weatherManager;
	std::list<Bullet *>listBullets;
	std::list<Monster *>listMonsters;
	std::list<int>rain;

public:
	Game(int wS, char fG, char pG, char bgL, char bgR, char mG, char mshG, int l, int s, int rL);
	int getWorldSize();
	int getLives();
	void setLives(int l);
	int getScore();
	void setScore(int s);
	char getPlayerGraphic();
	char getFloorGraphic();
	void setWorldSize(int w);
	void setPlayerGraphic(char g);
	void setFloorGraphic(char g);
	void paintWorld();
	void respawnWorld();
	void movePlayerLeft();
	void movePlayerRight();
	void firePlayerLeft();
	void firePlayerRight();
	void generateMonster();
	void generateMushroom();
	bool checkHitMonster(int nextPos, int bullPos);
	bool checkHitPlayer(int nextPos, int monPos);
	bool checkMushroomPicked();
	bool createFrame();
	void gameOver();
	void makeRain();
	void printGameOver();
	void printHeader();
};



