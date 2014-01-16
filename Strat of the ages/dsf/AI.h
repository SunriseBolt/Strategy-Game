#pragma once
#include "Pathfinding.h"
#include "Map.h"

enum states {WAR, PEACE, RETREAT};

class AI
{
public:
	AI();
	// Check for a nearby player, and go to/attack them.  If no player is nearby, go to closest unoccupied province
	// Eventually will begin wandering, finding the closest province and heading there, enemy provinces taking priority
	void moveToClosest();
	void checkForPlayer();
};