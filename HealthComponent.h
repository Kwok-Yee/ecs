#pragma once
#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent(int h) { health = h; }
	int getHealth() { return health; }
	void SetHealth(int h) { health = h; }
	TYPE getType() { return type; }
private:
	TYPE type = TYPE::HEALTH;
	int health;
};