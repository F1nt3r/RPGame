#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	string characterName;		// ��������
	int health;					// ��������
	int damage;					// ����
	string weapon;				// ������
	string damageType;			// ��� �����
	int strength;				// ����
	int dexterity;				// ��������
	int endurance;				// ������������
	void setCharacterName(string characterName);
	void setHealth(int health);
	void setDamage(int damage);
	void setDamageType(string damageType);
	void setRascal();
	void setWarrior();
	void setBarbarian();
};