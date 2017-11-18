#include "stdafx.h"
#include "game.h"

Game::Game(int wS, char fG, char pG, char bgL, char bgR, char mG, char mshG, int l, int s, int rL) {
	worldSize			= wS;
	floorGraphic		= fG;
	playerGraphic		= pG;
	bulletGraphicLeft	= bgL;
	bulletGraphicRight	= bgR;
	monsterGraphic		= mG;
	mushroomGraphic		= mshG;
	lives				= l;
	score				= s;
	player				= new Player(worldSize / 2);
	bulletAmount		= 0;
	monsterAmount		= 0;
	mushroomAmount		= 0;	
	weatherManager		= new WeatherManager(weatherRainLevel, worldSize);
}

int Game::getWorldSize() {
	return worldSize;
}

int Game::getLives() {
	return lives;
}

int Game::getScore() {
	return score;
}

void Game::setLives(int l) {
	lives = l;
}

void Game::setScore(int s) {
	score = s;
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

bool Game::createFrame() {
	//Update Monsters
	for (auto mon = listMonsters.begin(); mon != listMonsters.end();) {
		int monPos	= (*mon)->getPos();
		int monDir	= (*mon)->getDirection();
		int nextPos = (*mon)->move();
		if ((nextPos >= 0) && (nextPos <= worldSize - 1)) {
			if (checkHitPlayer(nextPos, monPos)) {
				//Player Dead
				if (lives > 1) {
					lives--;
				}
				else {
					//GameOver
					return false;
				}
				respawnWorld();
				return true;
			}
			mon++;
		}
		else {
			mon = listMonsters.erase(mon);
			monsterAmount--;
		}
	}
	
	//Update Bullets
	for (auto bull = listBullets.begin(); bull != listBullets.end();){
		int bullPos = (*bull)->getPos();
		int bullDir = (*bull)->getDirection();
		int nextPos = (*bull)->move();
		if ((nextPos >= 0) && (nextPos <= worldSize - 1)) {
			if(checkHitMonster(nextPos,bullPos)){
				bull = listBullets.erase(bull);
				score += monsterKillPoints;
				bulletAmount--;
			}
			else {
				bull++;
			}
		}
		else {
			bull = listBullets.erase(bull);
			bulletAmount--;
		}
	}
	checkMushroomPicked();

	return true;
	
}

void Game::paintWorld() {

	//World
	char world[100] = "";
	for (int i = 0; i < worldSize; i++)
		world[i] = floorGraphic;

	//Weather
	for (auto rainPos = rain.begin(); rainPos != rain.end();) {
		world[(*rainPos)] = ',';
		rainPos++;
	}


	//Setting World Bullets
	for (auto bull = listBullets.begin(); bull != listBullets.end();)
	{
		int bullPos = (*bull)->getPos();
		int bullDir = (*bull)->getDirection();
		if (!bullDir)
			world[(*bull)->getPos()] = bulletGraphicLeft;
		else
			world[(*bull)->getPos()] = bulletGraphicRight;
		bull++;
	}
	//Setting World Monsters
	for (auto mon = listMonsters.begin(); mon != listMonsters.end();) {
		int monPos = (*mon)->getPos();
		world[(*mon)->getPos()] = monsterGraphic;
		mon++;
	}
	//Setting Mushroom
	world[mushroom->getPos()] = mushroomGraphic;
	//Setting Player
	world[player->getPos()] = playerGraphic;

	//Screen Render
	printf("\r");
	printf("		%s  ", world);
	printf("LIVES: %4d   SCORE: %5d", lives, score);

}

void Game::respawnWorld() {
	for (Bullet* bull : listBullets) delete bull;
	listBullets.clear();

	for (Monster* mon : listMonsters) delete mon;
	listMonsters.clear();

	bulletAmount = 0;
	monsterAmount = 0;
	player->setPos(worldSize / 2);
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
		Bullet *bullet = new Bullet(player->getPos()-1, 0);
		listBullets.push_back(bullet);
	}
}

void Game::firePlayerRight() {
	if (player->getPos() < worldSize -1) {
		Bullet *bullet = new Bullet(player->getPos()+1, 1);
		listBullets.push_back(bullet);
	}
}

void Game::generateMonster() {
	if (monsterAmount < 3) {
		int direction = rand() % 2;
		if (!direction) {
			Monster *monster = new Monster(worldSize-1, direction);
			listMonsters.push_back(monster);
		}
		else {
			Monster *monster = new Monster(0, direction);
			listMonsters.push_back(monster);
		}
		monsterAmount++;		
	}
}

void Game::generateMushroom() {
	if (mushroomAmount < 1) {
		int randPos = rand() % worldSize;
		this->mushroom = new Mushroom(randPos, mushroomBonusPoints);
		mushroomAmount++;
	}
}


bool Game::checkHitMonster(int nextPos, int bullPos) {
	bool hit = false;
	for (auto mon = listMonsters.begin(); mon != listMonsters.end();) {
		int monPos = (*mon)->getPos();
		if ((bullPos == monPos) || (nextPos == monPos)) {
			hit = true;
			mon = listMonsters.erase(mon);
			monsterAmount--;
			return hit;
		}
		else {
			mon++;
		}
			
	}
	return hit;
}

bool Game::checkHitPlayer(int nextPos, int monPos) {
	int playerPos = player->getPos();
	if ((nextPos == playerPos) || (monPos == playerPos)) {
		return true;
	}
	else {
		return false;
	}
}

bool Game::checkMushroomPicked() {
	int playerPos = player->getPos();
	int mushPos = mushroom->getPos();
	if (mushPos == playerPos) {
		score += mushroomBonusPoints;
		mushroomAmount--;
		return true;
	}
	else {
		return false;
	}
}

void Game::makeRain() {
	rain = weatherManager->generateRain(worldSize);
}

void Game::gameOver() {
	system("cls");
	printf("GAME OVER!!");

}

