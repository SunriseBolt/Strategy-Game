#pragma once
#include "Nation.h"
#include "Loc.h"
#include "Pallette.h"

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
			ATK = 1;
			DEF = 1;
		}
		else if(m_type == CAVALIER)
		{
			ATK = 3;
			DEF = 4;
		}
		else if(m_type == ARTILLERY)
		{
			ATK = 2;
			DEF = 2;
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
	Nation* n;
	Loc l;
	Soldier s[1000];
public:
	Army();
	void setNation(Nation*);
	Nation* getNation(Army&){return n;}
	void moveTo(pallette*, int);
};