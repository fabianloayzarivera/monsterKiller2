#include "stdafx.h"
#include "monster.h"

Monster::Monster(int p, int d) {
	pos = p;
	direction = d;
}
int Monster::getPos() {
	return pos;
}

void Monster::setPos(int p) {
	pos = p;
}

int Monster::getDirection() {
	return direction;
}

void Monster::setDirection(int d) {
	direction = d;
}

int Monster::move() {
	if (!direction) {
		//moving left
		pos--;
		return pos;
	}
	else {
		pos++;
		return pos;
	}
}