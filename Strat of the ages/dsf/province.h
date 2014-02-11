#pragma once
#define NULL 0
struct Province{

	bool Set;

	int mtype;
	int connections[6];
	long long mID;
	float mTax;
	float mManpower;
	int m_NationID;
	int x,y;
	Province(){
	Set = false;


	mtype = 0;
	for(int i = 0; i < 6 ;i++)
		connections[i] = 0;
	mID = 0;
	mTax = 0;
	mManpower = 0;
	m_NationID = 0;

	}

	Province(int atype,long long aID,float aTax, float aManpower,int a_x,int a_y):mtype(atype),mID(aID),mTax(aTax),mManpower(aManpower),m_NationID(-1),x(a_x),y(a_y){//don't try to understand this if you don't want to.
		Set = false;
		
		if(aID%100 == 0)
			connections[0]=-1;
		else
			connections[0] = aID-1;
		
		if((float)aID/100.0 < 1.0){
			connections[1]=-1;
			connections[2]=-1;
		}
		else
			if((aID/100)%2 == 0){
				connections[1]=aID-101;
				connections[2]=aID-100;
			}
			else{
				connections[1]=aID-100;
				connections[2]=aID-99;
			}

		if(aID%100 == 99)
			connections[3]=-1;
		else
			connections[3]=aID+1;

		if((float)aID/100.0 > 99.0){
			connections[4]=-1;
			connections[5]=-1;}
		else
			if((aID/100)%2 == 0){
				connections[5]=aID+99;
				connections[4]=aID+100;}
			else{
				connections[5]=aID+100;
				connections[4]=aID+101;}
		//aID%100 == 0 ? connections[0]=NULL : connections[0] = aID-1;
		//aID/100 == 0 ? connections[1]=NULL, connections[2]=NULL : (aID/100)%2 == 0 ? connections[1]=aID-101, connections[2]=aID-100 : connections[1]=aID-100, connections[2]=aID-99 ;
		//aID%100 == 99 ? connections[3]=NULL : connections[3]=aID+1;
		//aID/100 == 99 ? connections[4]=NULL, connections[5]=NULL : (aID/100)%2 == 0 ? connections[5]=aID+99, connections[4]=aID+100 : connections[5]=aID+100, connections[4]=aID+101 ;
	
		for(int i = 0; i < 6; i++){
			if(connections[i] > 9999)
				connections[i] = -1;
		}
	}

};