#pragma once
#include "Nation.h"
#include "Loc.h"

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
	Nation n;
	Loc l;
	Soldier s[1000];
public:
	Army():m_techLvl(0),m_numInf(0), m_numCav(0), m_numArt(0),m_morale(1.0)
	{
		n.m_Name = "NULL";
	}
	Army(Nation &nation, Loc &location, int a_numCav, int a_numInf, int a_numArt);
};