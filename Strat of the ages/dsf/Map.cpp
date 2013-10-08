#include "Map.h"
#include <fstream>

WorldMap::WorldMap(){
	Province * Prov;
	for(int i = 0; i < 500; i++)\
		for(int j = 0; j < 500; j++)
			Prov = new Province(2,i+j*500,1.0f,1.0f);
			Provinces.add((int)Prov);
}