#include "Army.h"


Army::Army():m_techLvl(0),m_numInf(3), m_numCav(2), m_numArt(1),m_morale(1.0),NumTroops(1000),NumMaxTroops(1000),NationID(0),Moving(false),Orders()
{
	Target = NULL;
	ProvID = 0;
	PlayerProvTarget = -1;
	isPlayers = false;
}

void Army::setNation(DWORD n)
{
	this->Nation = n;
}

bool Army::moveTo(int prov)
{
	if(ProvID > -1){
		ProvID = prov;
		Moving = false;
		return false;}
	return true;
	
}


void Army::CombatRound(Army* Enemy){
	if(m_State != Retreat){
		unsigned int die = rand()%20;
		float DmgMult = (((float)NumTroops/(float)Enemy->NumTroops)+1.0f)/2.0f;

		Enemy->NumTroops -= pow(die,1.5f)*DmgMult*(this->ATK/Enemy->DEF);
		Enemy->m_morale -= (pow(die,1.5f)*DmgMult*(this->MATK/Enemy->MDEF))/Enemy->NumTroops;

		PreviousDie = die;
	}
	else
	{
		if(rand()%4 == 0){
			Enemy->Target = 0;
			Target = 0;
			Enemy->setMoving(false);
			setMoving(false);
		}

	}
	if(Enemy->NumTroops < 1)
	{
		Enemy->NumTroops = 1;
		Enemy->m_State = Retreat;
	}
	if(Enemy->m_morale < 0){
		Enemy->m_State = Retreat;
		Enemy->m_morale = 0.0f;
	}
	if(this->NumTroops < 1)
	{
		this->NumTroops = 1;
		this->m_State = Retreat;
	}
	if(this->m_morale < 0){
		this->m_State = Retreat;
		this->m_morale = 0.0f;
	}

}


Army* Army::getTarget(){
	return Target;
}
void Army::setTarget(Army* a_tar){
	Target = a_tar;
}


void Army::SetCombatVal(int ATK,int DEF,int MATK,int MDEF,float maxMorale){
	this->ATK = ATK;
	this->DEF = DEF;
	this->MATK = MATK;
	this->MDEF = MDEF;
	this->maxMorale = maxMorale;
}

