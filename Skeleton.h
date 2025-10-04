#pragma once
#include "Enemy.h"
#include <iostream>

using std::string;

class Skeleton : public Enemy
{
public:
	Skeleton();
	int feature(string damageType) override;
};