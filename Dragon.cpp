#include "Dragon.h"

using namespace std;

Dragon::Dragon()
{
	setEnemyType("Dragon");
	setHealth(20);
	setDamage(4);
	setWeapon("Legendary sword");
	setWeaponDamage(10);
	setDamageType("Chopping");
	setStrength(3);
	setDexterity(3);
	setEndurance(3);
}

int Dragon::feature() { return 3; }