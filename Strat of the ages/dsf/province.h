#pragma once
#ifndef NULL
#define NULL 0
#endif

struct Province{
	static const int Ocean = 0,Coast = 1,Land = 2;
	int mtype;
	int connections[6];
	long long mID;
	float mTax;
	float mManpower;
	Province():mtype(0),mID(0),mTax(0),mManpower(0){
		connections[0] = 0;
		connections[1] = 0;
		connections[2] = 0;
		connections[3] = 0;
		connections[4] = 0;
		connections[5] = 0;

	}
	Province(int atype,long long aID,float aTax, float aManpower):mtype(atype),mID(aID),mTax(aTax),mManpower(aManpower){//don't try to understand this if you don't want to.
		aID%500 == 0 ? connections[0]=NULL : connections[0] = aID-1;
		aID/500 == 0 ? connections[1]=NULL, connections[2]=NULL : (aID/500)%2 == 0 ? connections[1]=aID-501, connections[2]=aID-500 : connections[1]=aID-500, connections[2]=aID-499 ;
		aID%500 == 499 ? connections[3]=NULL : connections[3]=aID+1;
		aID/500 == 499 ? connections[4]=NULL, connections[5]=NULL : (aID/500)%2 == 0 ? connections[5]=aID+499, connections[4]=aID+500 : connections[5]=aID+500, connections[4]=aID+501 ;
	}
	Province(Province & other):mtype(other.mtype),mID(other.mID),mTax(other.mTax),mManpower(other.mManpower){//don't try to understand this if you don't want to.
		for(int i = 0; i < 6; i++){
			connections[i]=other.connections[i];
		}
	}
};