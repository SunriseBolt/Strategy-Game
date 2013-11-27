#pragma once
#include "province.h"

#define Num_Landseed 50
#define Num_Forestseed 25
#define Num_Desertseed 25
#define Num_Moutainseed 3
#define Num_Waterseed 15
#define MapSize 100


class WorldMap{
	Province* Provinces[10000];
	
	enum {Land,Forest,Desert,Mountain,Water};
public:
	Province& getProv(int i);
	WorldMap();
	~WorldMap();
};