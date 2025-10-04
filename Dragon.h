#pragma once
#include "Enemy.h"
#include <iostream>

using std::string;

class Dragon : public Enemy
{
public:
	Dragon();
	int feature() override;
};