#pragma once
#include "Loc.h"
#include "ProvAI.h"

#include <d3d9.h>
#include <d3dx9.h>

const int INFANTRY = 0, CAVALIER = 1, ARTILLERY = 2;



class Army
{
private:
	bool Moving;
	bool isPlayers;

	int PlayerProvTarget;

	int NationalID;

	int m_techLvl, m_numCav, m_numInf, m_numArt;

	int m_State;

	float m_morale;
	DWORD Nation;
	int NationID;
	unsigned int NumTroops;
	unsigned int NumMaxTroops;
	int ProvID;
	
	int ATK, DEF, MATK, MDEF;
	float maxMorale;	

	int PreviousDie;
	Army* Target;
public:

	ProvAI Orders;

	enum{Peace,War,Retreat};//Used for AI state of an army
	Army();
	void setNation(DWORD);
	DWORD getNation(){
		return Nation;
	}
	void moveTo(int);
	void setMoving(bool a_Moving){Moving = a_Moving;};
	bool getMoving(){return Moving;};
	int getProvID(){return ProvID;};
	int getTroops(){return NumTroops;};
	int getDie(){return PreviousDie;};
	float getMorale(){return m_morale;};
	int getNationID(){		return NationID;};
	int getNationalID(){ return NationalID;};
	int getState(){return m_State;};
	int getPlayerProvTarget(){return PlayerProvTarget;};
	bool getisPlayers(){return isPlayers;};
	void setNationID(int NationID){this->NationID = NationID;};
	void setState(int a_State){this->m_State = a_State;};
	void setNationalID(int ID){this->NationalID = ID;};
	void setisPlayers(bool is){this->isPlayers = is;};
	void setPlayerProvTarget(int tar){this->PlayerProvTarget = tar;};
	//COMBAT
	//performs a single round of combat against an army
	void CombatRound(Army*);
	Army* getTarget();
	void setTarget(Army*);
	void SetCombatVal(int ATK,int DEF,int MATK,int MDEF,float maxMorale);
};