#include "Player.h"

void Player::setCharacterName(string characterName) { this->characterName = characterName; }

void Player::setHealth(int health) { this->health = health; }

void Player::setDamage(int damage) { this->damage = damage; }

void Player::setDamageType(string damageType) { this->damageType = damageType; }

void Player::setRascal()
{
	health = 4;
	damage = 2;
	damageType = "Stabbing";
}

void Player::setWarrior()
{
	health = 5;
	damage = 3;
	damageType = "Chopping";
}

void Player::setBarbarian()
{
	health = 6;
	damage = 3;
	damageType = "Crushing";
}