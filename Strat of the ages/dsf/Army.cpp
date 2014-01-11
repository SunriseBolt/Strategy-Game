#include "Army.h"


Army::Army():m_techLvl(0),m_numInf(3), m_numCav(2), m_numArt(1),m_morale(1.0)
{
	ProvID = 0;
}

void Army::setNation(Nation* n)
{
	this->n = n;
}

void Army::moveTo(int prov)
{
	ProvID = prov;
}