#pragma once
#include "Enemy.h"
#include <iostream>

using std::string;

class Golem : public Enemy
{
public:
	Golem();
	int feature() override;
};