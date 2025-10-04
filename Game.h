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
	int round = 1;				// Текущий раунд
	int rascalLvl = 0;			// Уровень разбойника
	int warriorLvl = 0;			// Уровень воина
	int barbarianLvl = 0;		// Уровень варвара
public:
	void chooseCharacter();
	void upgradeCharacter();
	void changeCharacter();
	void chooseEnemy();
	int fight();
	void win();
	void lose();
};