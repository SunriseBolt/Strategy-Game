#pragma once
#include "Manager.h"
#include "province.h"


struct ProvAI{
	Manager<int> ProvQue;
	int weight;
	bool operator < (ProvAI other){
		if(weight < other.weight)
			return true;
		return false;
	}
	bool operator > (ProvAI other){
		if(weight > other.weight)
			return true;
		return false;
	}
	ProvAI():weight(0){}

};