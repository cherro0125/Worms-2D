#pragma once
#include "Weapon.h"

class Bazooka : public Weapon
{
public:
	Bazooka() = delete;
	Bazooka(float x, float y);
	virtual ~Bazooka() = default;
private:
	std::string bazookaTexturePath = "resources/images/bazooka.png";

	
};
