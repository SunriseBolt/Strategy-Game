#include "Map.h"
#include <fstream>

WorldMap::WorldMap(){
	Province * Prov;
	for(int i = 0; i < 100; i++)\
		for(int j = 0; j < 100; j++){
			Prov = new Province(2,j+i*100,1.0f,1.0f);
			Provinces[j+i*100] = Prov;}
}

Province WorldMap::getProv(int i){
	return* Provinces[i];
}

WorldMap::~WorldMap(){
	for(int i = 0; i < 10000; i++)
		if(Provinces[i]){
			delete Provinces[i];
			Provinces[i] = 0;
		}
}