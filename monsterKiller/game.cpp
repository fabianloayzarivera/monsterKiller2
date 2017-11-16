#include "stdafx.h"
#include "game.h"

Game::Game(int wS, char fG, char pG, char bgL, char bgR) {
	worldSize = wS;
	floorGraphic = fG;
	playerGraphic = pG;
	bulletGraphicLeft = bgL;
	bulletGraphicRight = bgR;
	player = new Player(worldSize / 2);
	
}
int Game::getWorldSize() {
	return worldSize;
}

char Game::getPlayerGraphic() {
	return playerGraphic;
}


char Game::getFloorGraphic() {
	return floorGraphic;
}

void Game::setFloorGraphic(char g) {
	floorGraphic = g;
}

void Game::setPlayerGraphic(char g) {
	playerGraphic = g;
}

void Game::setWorldSize(int w) {
	worldSize = w;
}

void Game::createFrame() {
	for (auto bull = listBullets.begin(); bull != listBullets.end();){
		int bullPos = (*bull)->getPos();
		int bullDir = (*bull)->getDirection();
		int nextPos = (*bull)->move();
		if ((nextPos >= 0) && (nextPos <= worldSize - 1)) {
			bull++;
		}
		else {
			bull = listBullets.erase(bull);
			bulletAmount--;
		}

	}
}

void Game::paintWorld() {
	char world[100] = "";
	for (int i = 0; i < worldSize; i++)
		world[i] = floorGraphic;

	for (auto bull = listBullets.begin(); bull != listBullets.end();)
	{
		int bullPos = (*bull)->getPos();
		int bullDir = (*bull)->getDirection();
		if ((bullPos >= 0) && (bullPos <= worldSize - 1)) {
			if (!bullDir)
				world[(*bull)->getPos()] = bulletGraphicLeft;
			else
				world[(*bull)->getPos()] = bulletGraphicRight;
			bull++;
		}
		else {
			bull = listBullets.erase(bull);
			bulletAmount--;
		}


	}

	world[player->getPos()] = playerGraphic;

	printf("\r");
	printf("		%s  ", world);

}

void Game::movePlayerLeft() {

	if (player->getPos() > 0)
		player->moveLeft();
}

void Game::movePlayerRight() {
	if (player->getPos() < worldSize-1)
		player->moveRight();
}

void Game::firePlayerLeft() {
	if (player->getPos() > 0) {
		Bullet *bullet = new Bullet(player->getPos() - 1, 0);
		listBullets.push_back(bullet);
	}
}

void Game::firePlayerRight() {
	if (player->getPos() < worldSize -1) {
		Bullet *bullet = new Bullet(player->getPos() + 1, 1);
		listBullets.push_back(bullet);
	}
}