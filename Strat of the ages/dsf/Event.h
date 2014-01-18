#pragma once
#include "Date.h"

struct Event{
	Date Time;
	enum{
		ArmyMove,ProvinceFlip
	};
	int ID;
	int Info[3];
	Event(){
		ID = 0;
	}

	void SetTime(Date a_Time){
		Time = a_Time;
	}

	bool operator< (Event other){
		if(Time < other.Time)
			return true;
		return false;
	}
		bool operator> (Event other){
		if(Time > other.Time)
			return true;
		return false;
	}
};