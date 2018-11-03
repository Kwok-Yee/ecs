#pragma once
#include "Component.h"

class ControlComponent : public Component
{
public:
	ControlComponent() {}
	void move() { };
	bool getIsMoving() { return isMoving; }
	TYPE getType() { return type; }
private:
	TYPE type = TYPE::CONTROL;
	bool isMoving = false;
};