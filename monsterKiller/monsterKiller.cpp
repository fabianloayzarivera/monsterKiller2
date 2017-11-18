// monsterKiller.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <conio.h>
#include <list>
#include <iostream>
#include "game.h"
using namespace std;


#define KEY_ESCAPE 27
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_FIRE_LEFT 122
#define KEY_FIRE_RIGHT 99

int main() {
	
	int key	= 0;	
	Game gameObject(75, '_', '|', '<', '>', 'Q', '@', 5, 0, 3);
	
	printf("\n\n\n\n\n\n");	
	while (key != KEY_ESCAPE) {
		
		if (_kbhit()) {
			key = _getch();
			
			if (key == KEY_LEFT)
				gameObject.movePlayerLeft();
			if (key == KEY_RIGHT)
				gameObject.movePlayerRight();
			if (key == KEY_FIRE_LEFT)
				gameObject.firePlayerLeft();
			if (key == KEY_FIRE_RIGHT)
				gameObject.firePlayerRight();

		}
		// Update.
		gameObject.generateMonster();
		gameObject.generateMushroom();
		gameObject.makeRain();
		
		// Render.
		if (gameObject.createFrame()) {
			gameObject.paintWorld();
			Sleep(50);
		}
		else {
			gameObject.gameOver();
			_getch();
			return 0;
		}
		
		
	}

}

