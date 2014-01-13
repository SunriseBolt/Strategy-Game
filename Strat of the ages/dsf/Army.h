#pragma once
#include "Loc.h"

#include <d3d9.h>
#include <d3dx9.h>

const int INFANTRY = 0, CAVALIER = 1, ARTILLERY = 2;

struct Soldier
{
	int m_type;
	int ATK, DEF, m_ATK, m_DEF;
	float maxMorale;
	void setCombatVals(int m_type)
	{
		//Mostly placeholder values
		if(m_type == INFANTRY)
		{
			ATK = 2;
			DEF = 2;
		}
		else if(m_type == CAVALIER)
		{
			ATK = 3;
			DEF = 1;
		}
		else if(m_type == ARTILLERY)
		{
			ATK = 1;
			DEF = 3;
		}
	}
	void setType(int a_type)
	{
		m_type = a_type;
	}
};

class Army
{
private:
	int m_techLvl, m_numCav, m_numInf, m_numArt;
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
	Army();
	void setNation(DWORD);
	DWORD getNation(){
		return Nation;
	}
	void moveTo(int);
	int getProvID(){
		return ProvID;};
	int getTroops(){return NumTroops;};
	int getDie(){return PreviousDie;};
	float getMorale(){return m_morale;};
	int getNationID(){
		return NationID;};
	void setNationID(int NationID){this->NationID = NationID;};
	//COMBAT
	//performs a single round of combat against an army
	void CombatRound(Army*);
	Army* getTarget();
	void setTarget(Army*);
	void SetCombatVal(int ATK,int DEF,int MATK,int MDEF,float maxMorale);
};