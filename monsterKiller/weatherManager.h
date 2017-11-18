#pragma once
#include <list>
#include <iostream>

class WeatherManager {
private:
	std::list<int> rainPositions;
	int rainLevel;
public:
	WeatherManager(int rL, int worldSize);
	std::list<int> getRain();
	int getRainLevel();
	void setRainLevel(int rL);
	std::list<int> generateRain(int worldSize);

};