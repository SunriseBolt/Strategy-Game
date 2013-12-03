#pragma once
#include "province.h"

#define Num_Landseed 50
#define Num_Forestseed 25
#define Num_Desertseed 25
#define Num_Moutainseed 3
#define Num_Waterseed 15
#define Num_Nations 100

//Complete placeholder values
#define LandWeight 1
#define ForestWeight 2
#define DesertWeight 4
#define MountainWeight 6
#define WaterWeight 3

class WorldMap{
	Province* Provinces[10000];
	
public:
	enum {Land,Forest,Desert,Mountain,Water};
	Province& getProv(int i);
	WorldMap();
	~WorldMap();
};