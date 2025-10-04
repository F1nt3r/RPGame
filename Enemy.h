#pragma once
#include <iostream>

using namespace std;

class Enemy
{
public:
	string enemyType;		// ��� �����
	int health;				// ��������
	int damage;				// ����
	string weapon;			// ������
	int weaponDamage;		// ���� ������ (�� ������ � ������ �����)
	string damageType;		// ��� �����
	int strength;			// ����
	int dexterity;			// ��������
	int endurance;			// ������������
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