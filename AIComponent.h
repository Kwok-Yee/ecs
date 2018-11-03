#pragma once
#include "Component.h"

class AIComponent : public Component
{
public:
	AIComponent() { }
	int getIsAI() { return isAI; }
	void setIsAI(bool b) { isAI = b; }
	TYPE getType() { return type; }
private:
	TYPE type = TYPE::AI;
	bool isAI = true;
};