﻿#pragma once
#include "Weapon.h"

class Bazooka : public Weapon
{
public:
	Bazooka() = delete;
	Bazooka(float x, float y);
	virtual ~Bazooka() = default;
	void playShootSound() override;
private:
	std::string bazookaTexturePath = "resources/images/bazooka.png";

	
};
