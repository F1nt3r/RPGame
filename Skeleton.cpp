#include "Skeleton.h"

using namespace std;

Skeleton::Skeleton()
{
	setEnemyType("Skeleton");
	setHealth(10);
	setDamage(2);
	setWeapon("Cudgel");
	setWeaponDamage(3);
	setDamageType("Crushing");
	setStrength(2);
	setDexterity(2);
	setEndurance(1);
}

int Skeleton::feature(string damageType) { if (damageType == "Crushing") return 2; else return 1; }