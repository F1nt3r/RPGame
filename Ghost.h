#pragma once
#include "Enemy.h"
#include <iostream>

using std::string;

class Ghost : public Enemy
{
public:
	Ghost();
	int feature(int playerDexterity) override;
};