#pragma once
#include "Nation.h"
#define NULL 0
struct Province{
	static const int Ocean = 0,Coast = 1,Land = 2;
	int mtype;
	int connections[6];
	long long mID;
	float mTax;
	float mManpower;
	Nation* m_Nation;
	Province(int atype,long long aID,float aTax, float aManpower):mtype(atype),mID(aID),mTax(aTax),mManpower(aManpower),m_Nation(NULL){//don't try to understand this if you don't want to.
		aID%100 == 0 ? connections[0]=NULL : connections[0] = aID-1;
		aID/100 == 0 ? connections[1]=NULL, connections[2]=NULL : (aID/100)%2 == 0 ? connections[1]=aID-101, connections[2]=aID-100 : connections[1]=aID-100, connections[2]=aID-99 ;
		aID%100 == 99 ? connections[3]=NULL : connections[3]=aID+1;
		aID/100 == 99 ? connections[4]=NULL, connections[5]=NULL : (aID/100)%2 == 0 ? connections[5]=aID+99, connections[4]=aID+100 : connections[5]=aID+100, connections[4]=aID+101 ;
			
	}
};