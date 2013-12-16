#include "Army.h"

Army::Army(Nation* nation, int a_numInf, int a_numCav, int a_numArt)
{
	setNation(nation);
	m_techLvl = 0, m_numInf = a_numInf, m_numCav = a_numCav, m_numArt = a_numArt, m_morale = 1.0;
	// Ugly way of setting the first 5 army units
	for(int i = 0; i < 5; i++)
	{
		if(i < a_numInf)
			s[i].setType(INFANTRY);
		else if(i-a_numInf < a_numCav)
			s[i].setType(CAVALIER);
		else if(i-(a_numInf+a_numArt) < a_numArt)
			s[i].setType(ARTILLERY);
	}
}

void Army::setNation(Nation* n)
{
	this->n = n;
}