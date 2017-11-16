#include "stdafx.h"
#include "player.h"

Player::Player(int p) {
	pos = p;
}

int Player::getPos() {
	return pos;
}

void Player::setPos(int p) {
	pos = p;
}

int Player::moveLeft() {
	pos--;
	return pos;
}

int Player::moveRight() {
	pos++;
	return pos;
}
