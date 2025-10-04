#include "Slime.h"

using namespace std;

Slime::Slime()
{
	setEnemyType("Slime");
	setHealth(8);
	setDamage(1);
	setWeapon("Spear");
	setWeaponDamage(3);
	setDamageType("Stabbing");
	setStrength(3);
	setDexterity(1);
	setEndurance(2);
}

int Slime::feature(string damageType) { if (damageType == "Chopping") return 0; else return 1; }