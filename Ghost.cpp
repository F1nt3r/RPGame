#include "Ghost.h"

using namespace std;

Ghost::Ghost()
{
	setEnemyType("Ghost");
	setHealth(6);
	setDamage(3);
	setWeapon("Sword");
	setWeaponDamage(3);
	setDamageType("Chopping");
	setStrength(1);
	setDexterity(3);
	setEndurance(1);
}

int Ghost::feature(int playerDexterity) { if (dexterity > playerDexterity) return 1; else return 0; }