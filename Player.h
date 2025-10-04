#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	string characterName;		// Персонаж
	int health;					// Здоровье
	int damage;					// Урон
	string weapon;				// Оружие
	string damageType;			// Тип урона
	int strength;				// Сила
	int dexterity;				// Ловкость
	int endurance;				// Выносливость
	void setCharacterName(string characterName);
	void setHealth(int health);
	void setDamage(int damage);
	void setDamageType(string damageType);
	void setRascal();
	void setWarrior();
	void setBarbarian();
};