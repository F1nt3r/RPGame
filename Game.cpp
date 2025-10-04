#include "Game.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "Slime.h"
#include "Ghost.h"
#include "Golem.h"
#include "Dragon.h"

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

void Game::chooseCharacter()
{
	cout << "Choose your character (R - Rascal, W - Warrior, B - Barbarian):" << endl;
	player.strength = rand() % 3 + 1;
	player.dexterity = rand() % 3 + 1;
	player.endurance = rand() % 3 + 1;
	cout << "Strength - " << player.strength << ", Dexterity - " << player.dexterity
		<< ", Endurance - " << player.endurance << endl;
	cin >> character;
	if (character == "R")
	{
		player.setRascal();
		rascalLvl += 1;
	}
	else if (character == "W")
	{
		player.setWarrior();
		warriorLvl += 1;
	}
	else if (character == "B")
	{
		player.setBarbarian();
		barbarianLvl += 1;
	}
	
}

void Game::upgradeCharacter()
{
	cout << "Change or upgrade your character (R - Rascal, W - Warrior, B - Barbarian):" << endl
		<< "Rascal lvl - " << rascalLvl << ", Warrior lvl - " << warriorLvl
		<< ", Barbarian lvl - " << barbarianLvl << endl
		<< "Strength - " << player.strength << ", Dexterity - "
		<< (rascalLvl >= 2 ? player.dexterity + 1 : player.dexterity)
		<< ", Endurance - " << player.endurance << endl;
	cin >> character;
	if (character == "R") rascalLvl += 1;
	else if (character == "W") warriorLvl += 1;
	else if (character == "B") barbarianLvl += 1;
	int answer;
	cout << "Wanna replace your weapon with " << enemy->enemyType << "'s "
		<< enemy->weapon << "? (1 - Yes, 2 - No)" << endl
		<< "Your weapon stats: Damage - " << player.damage << ", Damage Type - " << player.damageType << endl
		<< enemy->weapon << "'s stats: Damage - " << enemy->weaponDamage
		<< ", Damage type - " << enemy->damageType << endl;
	cin >> answer;
	if (answer == 1)
	{
		player.weapon = enemy->weapon;
		player.damage = enemy->weaponDamage;
		player.damageType = enemy->damageType;
	}
}

void Game::changeCharacter()
{
	cout << "Rascal lvl - " << rascalLvl << ", Warrior lvl - " << warriorLvl
		<< ", Barbarian lvl - " << barbarianLvl << endl
		<< "Strength - " << player.strength << ", Dexterity - "
		<< (rascalLvl >= 2 ? player.dexterity + 1 : player.dexterity)
		<<", Endurance - " << player.endurance << endl;
	int answer;
	cout << "Wanna replace your weapon with " << enemy->enemyType << "'s "
		<< enemy->weapon << "? (1 - Yes, 2 - No)" << endl
		<< "Your weapon stats: Damage - " << player.damage << ", Damage Type - " << player.damageType << endl
		<< enemy->weapon << "'s stats: Damage - " << enemy->weaponDamage
		<< ", Damage type - " << enemy->damageType << endl;
	cin >> answer;
	if (answer == 1)
	{
		player.weapon = enemy->weapon;
		player.damage = enemy->weaponDamage;
		player.damageType = enemy->damageType;
	}
}

void Game::chooseEnemy()
{
	int randomEnemy = rand() % 6 + 1;
	switch (randomEnemy)
	{
	case 1:
		enemy = new Goblin();
		break;
	case 2:
		enemy = new Skeleton();
		break;
	case 3:
		enemy = new Slime();
		break;
	case 4:
		enemy = new Ghost();
		break;
	case 5:
		enemy = new Golem();
		break;
	case 6:
		enemy = new Dragon();
		break;
	}
}

int Game::fight()
{
	int winner;	// 0 - враг, 1 - игрок
	int sumDexterity = player.dexterity + enemy->dexterity;
	int playerWeaponDamage = player.damage;
	int playerDexterity = player.dexterity;
	if (rascalLvl >= 2) playerDexterity += 1;
	if (warriorLvl == 3 && round == 3) player.strength += 1;
	if (barbarianLvl == 3 && round == 3) player.endurance += 1;
	player.health += player.endurance;
	int playerStrength = player.strength;
	int playerEndurance = player.endurance;
	int playerHealth = player.health;
	int enemyHealth = enemy->health + enemy->endurance;
	int playerDamage;
	if (enemy->enemyType == "Slime")
	{
		playerDamage = playerWeaponDamage *= enemy->feature(player.damageType) + playerStrength;
		if (rascalLvl >= 1 && playerDexterity > enemy->dexterity) playerDamage += 1;
	}
	else
	{
		if (rascalLvl >= 1 && playerDexterity > enemy->dexterity) playerWeaponDamage += 1;
		playerDamage = playerWeaponDamage + playerStrength;
	}
	if (enemy->enemyType == "Skeleton") playerDamage *= enemy->feature(player.damageType);
	if (enemy->enemyType == "Golem") playerDamage -= enemy->feature();
	int enemyDamage = enemy->damage + enemy->strength;
	if (enemy->enemyType == "Ghost") enemyDamage += enemy->feature(playerDexterity);
	if (warriorLvl >= 2 && playerStrength > enemy->strength) enemyDamage -= 3;
	if (barbarianLvl >= 2) enemyDamage -= playerEndurance;
	if (enemyDamage < 0) enemyDamage = 0;
	if (playerDamage < 0) playerDamage = 0;
	system("cls");
	for (int i = 0;; i++)
	{
		cout << "You: " << (playerHealth > 0 ? playerHealth : 0) << " HP" << endl;
		cout << "Enemy (" << enemy->enemyType << "): " << (enemyHealth > 0 ? enemyHealth : 0) << " HP" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		system("cls");
		if (rascalLvl == 3 && i >= 1) playerDamage += 1;
		if (warriorLvl >= 1 && i == 0)
		{
			playerDamage -= playerStrength;
			playerDamage *= 2;
			playerDamage += playerStrength;
		}
		if (warriorLvl >= 1 && i == 1)
		{
			playerDamage -= playerStrength;
			playerDamage /= 2;
			playerDamage += playerStrength;
		}
		if (barbarianLvl >= 1 && i == 0) playerDamage += 2;
		if (barbarianLvl >= 1 && i == 3) playerDamage -= 3;
		if (playerDamage < 0) playerDamage = 0;
		if (enemy->enemyType == "Dragon" && i % 3 == 2) enemyDamage += enemy->feature();
		if (playerDexterity >= enemy->dexterity)
		{
			if (enemy->dexterity < rand() % sumDexterity + 1)
			{
				enemyHealth -= playerDamage;
				if (enemyHealth <= 0)
				{
					winner = 1;
					break;
				}
			}
			else
			{
				system("cls");
				cout << "Your attack missed" << endl;
				this_thread::sleep_for(chrono::seconds(1));
				system("cls");
			}
			if (playerDexterity < rand() % sumDexterity + 1)
			{
				playerHealth -= enemyDamage;
				if (playerHealth <= 0)
				{
					winner = 0;
					break;
				}
			}
			else
			{
				system("cls");
				cout << "Enemy's attack missed" << endl;
				this_thread::sleep_for(chrono::seconds(1));
				system("cls");
			}
		}
		else
		{
			if (playerDexterity < rand() % sumDexterity + 1)
			{
				playerHealth -= enemyDamage;
				if (playerHealth <= 0)
				{
					winner = 0;
					break;
				}
			}
			else
			{
				system("cls");
				cout << "Enemy's attack missed" << endl;
				this_thread::sleep_for(chrono::seconds(1));
				system("cls");
			}
			if (enemy->dexterity < rand() % sumDexterity + 1)
			{
				enemyHealth -= playerDamage;
				if (enemyHealth <= 0)
				{
					winner = 1;
					break;
				}
			}
			else
			{
				system("cls");
				cout << "Your attack missed" << endl;
				this_thread::sleep_for(chrono::seconds(1));
				system("cls");
			}
		}
		if (enemy->enemyType == "Dragon" && i % 3 == 2) enemyDamage -= enemy->feature();
	}
	cout << "You: " << (playerHealth > 0 ? playerHealth : 0) << " HP" << endl;
	cout << "Enemy (" << enemy->enemyType << "): " << (enemyHealth > 0 ? enemyHealth : 0) << " HP" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	system("cls");
	cout << "Winner: " << (winner == 1 ? "You" : enemy->enemyType) << endl;
	this_thread::sleep_for(chrono::seconds(1));
	system("cls");
	round++;

	return (winner ? 1 : 0);
}

void Game::win()
{
	cout << "You won! Congratulations!" << endl;
}

void Game::lose()
{
	cout << "You lost :(" << endl;
}