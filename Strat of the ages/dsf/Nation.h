#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#include <string>
using namespace std;
#include "Army.h"
#include "Manager.h"
#include "province.h"

struct Nation{
	string m_Name;
	D3DXCOLOR m_Flag;

	double Treasury;
	double Manpower;
	float WarExhaustion;

	Manager<Province> ProvinceList;
	int NationalID;
	int m_CapitalID;

	int m_LandTech;
	int m_SeaTech;
	int m_EconomyTech;
	bool isUser;

	//Monetary Costs
	int upgradeCost;
	int ArmyCostMoney;
	int ArmyCostMen;
	int InfCostMoney;
	int InfCostMen;
	int CavCostMoney;
	int CavCostMen;
	int ArtCostMoney;
	int ArtCostMen;

	//Unit Stats
	float ArmyAtk;
	float ArmyDef;
	float ArmyMAtk;
	float ArmyMDef;
	float ArmyMaxMorale;

	//Army array
	Manager<Army> m_ArmyList;
	short NumMaxArmies;

	Manager<Nation> WarManager;

	Nation():m_LandTech(0),m_SeaTech(0),m_EconomyTech(0),NumMaxArmies(1),Treasury(100.0f),Manpower(1000.0f),WarExhaustion(0.0f),NationalID(0){

		m_Name = "";
		m_Flag = D3DCOLOR_ARGB(255,(rand()%155)+50,(rand()%155)+50,(rand()%155)+50);

		ArmyAtk = 1;
		ArmyDef = 1;
		ArmyMAtk = 1;
		ArmyMDef = 1;
		ArmyMaxMorale = 1.0;
		isUser = false;
		ArmyCostMoney = 10000;
		ArmyCostMen = 1000;
		InfCostMoney = 50;
		InfCostMen = 100;
		CavCostMoney = 200;
		CavCostMen = 200;
		ArtCostMoney = 200;
		ArtCostMen = 50;
	}
	
	Nation(string a_Name,int A, int R, int G,int B):m_LandTech(0),m_SeaTech(0),m_EconomyTech(0),NumMaxArmies(1),Treasury(100.0f),Manpower(1000.0f),NationalID(0){

		m_Name = a_Name;
		m_Flag = D3DCOLOR_ARGB(A,R,G,B);

		ArmyAtk = 0;
		ArmyDef = 0;
		ArmyMAtk = 0;
		ArmyMDef = 0;
		ArmyMaxMorale = 1.0;
		isUser = false;
		ArmyCostMoney = 10000;
		ArmyCostMen = 1000;
	}

	void UpdateUnitStats(){
		ArmyAtk += ArmyAtk * 0.1;
		ArmyDef += ArmyDef * 0.1;
		ArmyMAtk += ArmyMAtk * 0.1;
		ArmyMDef += ArmyMDef * 0.1;

		ArmyMaxMorale = 1;
	}

};