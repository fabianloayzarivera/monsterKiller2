#include "stdafx.h"
#include "weatherManager.h"

WeatherManager::WeatherManager(int rL, int worldSize) {
	rainLevel = rL;
	rainPositions.clear();
}


std::list<int> WeatherManager::getRain() {
	return rainPositions;
}

void WeatherManager::setRainLevel(int rL) {
	rainLevel = rL;
}

int WeatherManager::getRainLevel() {
	return rainLevel;
}

std::list<int> WeatherManager::generateRain(int worldSize) {
	rainPositions.clear();
	for (int i = 0; i < rainLevel; i++) {
		int randPos = rand() % worldSize;
		rainPositions.push_back(randPos);
	}
	return rainPositions;
		
}