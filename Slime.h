#pragma once
#include "Enemy.h"
#include <iostream>

using std::string;

class Slime : public Enemy
{
public:
	Slime();
	int feature(string damageType) override;
};