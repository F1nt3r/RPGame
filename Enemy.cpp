#include "Enemy.h"

void Enemy::setEnemyType(string enemyType) { this->enemyType = enemyType; }

void Enemy::setHealth(int health) { this->health = health; }

void Enemy::setDamage(int damage) { this->damage = damage; }

void Enemy::setWeapon(string weapon) { this->weapon = weapon; }

void Enemy::setWeaponDamage(int weaponDamage) { this->weaponDamage = weaponDamage; }

void Enemy::setDamageType(string damageType) { this->damageType = damageType; }

void Enemy::setStrength(int strength) { this->strength = strength; }

void Enemy::setDexterity(int dexterity) { this->dexterity = dexterity; }

void Enemy::setEndurance(int endurance) { this->endurance = endurance; }

int Enemy::feature(string damageType) {
	return 0;
}

int Enemy::feature(int playerDexterity) {
	return 0;
}

int Enemy::feature() {
	return 0;
}