#include "stdafx.h"
#include "mushroom.h"

Mushroom::Mushroom(int p, int bP) {
	pos = p;
	bonusPoints = bP;
}

int Mushroom::getPos() {
	return pos;
}

void Mushroom::setPos(int p) {
	pos = p;
}

int Mushroom::getBonusPoints() {
	return bonusPoints;
}

void Mushroom::setBonusPoints(int d) {
	bonusPoints = d;
}