#include "Golem.h"

using namespace std;

Golem::Golem()
{
	setEnemyType("Golem");
	setHealth(10);
	setDamage(1);
	setWeapon("Axe");
	setWeaponDamage(4);
	setDamageType("Chopping");
	setStrength(3);
	setDexterity(1);
	setEndurance(3);
}

int Golem::feature() { return endurance; }