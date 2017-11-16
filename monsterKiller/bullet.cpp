#include "stdafx.h"
#include "bullet.h"

Bullet::Bullet(int p, int d) {
	pos = p;
	direction = d;
}
int Bullet::getPos() {
	return pos;
}

void Bullet::setPos(int p) {
	pos = p;
}

int Bullet::getDirection() {
	return direction;
}

void Bullet::setDirection(int d) {
	direction = d;
}

int Bullet::move() {
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