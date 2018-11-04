#pragma once
#include "Component.h"

class AIComponent : public Component
{
public:
	AIComponent(int v) { velocity = v; }
	int getVelocity() { return velocity; }
	TYPE getType() { return type; }
private:
	TYPE type = TYPE::AI;
	int velocity;
};