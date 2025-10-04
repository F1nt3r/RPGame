#pragma once
#include <iostream>

using namespace std;

class Enemy
{
public:
	string enemyType;		// Тип врага
	int health;				// Здоровье
	int damage;				// Урон
	string weapon;			// Оружие
	int weaponDamage;		// Урон оружия (не связан с уроном врага)
	string damageType;		// Тип урона
	int strength;			// Сила
	int dexterity;			// Ловкость
	int endurance;			// Выносливость
	void setEnemyType(string enemyType);
	void setHealth(int health);
	void setDamage(int damage);
	void setWeapon(string weapon);
	void setWeaponDamage(int weaponDamage);
	void setDamageType(string damageType);
	void setStrength(int strength);
	void setDexterity(int dexterity);
	void setEndurance(int endurance);
	virtual int feature(string damageType);
	virtual int feature(int playerDexterity);
	virtual int feature();
};