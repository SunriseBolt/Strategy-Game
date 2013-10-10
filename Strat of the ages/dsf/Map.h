#pragma once
#include "province.h"

class WorldMap{
	Province* Provinces[10000];

public:
	Province getProv(int i);
	WorldMap();
	~WorldMap();
};