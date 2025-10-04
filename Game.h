#pragma once
#include "Player.h"
#include "Enemy.h"
#include <string>
#include <vector>

using namespace std;

class Game
{
	string character;
	Player player;
	Enemy* enemy;
	int round = 1;				// ������� �����
	int rascalLvl = 0;			// ������� ����������
	int warriorLvl = 0;			// ������� �����
	int barbarianLvl = 0;		// ������� �������
public:
	void chooseCharacter();
	void upgradeCharacter();
	void changeCharacter();
	void chooseEnemy();
	int fight();
	void win();
	void lose();
};