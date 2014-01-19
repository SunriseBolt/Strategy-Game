#pragma once
#include "province.h"
#include "Army.h"

enum {Land,Forest,Desert,Mountain,Water,WaterLand};

#define Num_Landseed 50
#define Num_Forestseed 25
#define Num_Desertseed 25
#define Num_Moutainseed 3
#define Num_Waterseed 15
#define Num_Nations 100

//Complete placeholder values
#define LandWeight 15
#define ForestWeight 20
#define DesertWeight 25
#define MountainWeight 60
#define WaterWeight 5
#define WaterLandWeight 60

class WorldMap{
	Province* Provinces[10000];
	
public:
	enum {Land,Forest,Desert,Mountain,Water,WaterLand};
	Province& getProv(int i);
	int Weight[6];
	WorldMap();
	void Init(Army[]);
	~WorldMap();
	void Reset(){
		for(int i = 0; i < 10000; i++){
			Provinces[i]->Set = false;
		}
	}
};