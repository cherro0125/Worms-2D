#pragma once
#include "Weapon.h"

class Revolver : public Weapon
{
public:
	Revolver() = delete;
	Revolver(float x, float y);
	virtual ~Revolver() = default;
	void playShootSound() override;
private:
	std::string revolverTexturePath = "resources/images/gun.png";
};
