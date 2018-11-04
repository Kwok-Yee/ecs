#pragma once
#include "Component.h"

enum STATE
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class ControlComponent : public Component
{
public:
	ControlComponent(int v) { velocity = v; }
	int getVelocity() { return velocity; }
	TYPE getType() { return type; }
	void setState(STATE s) { state = s; }
	STATE getState() { return state; }
private:
	TYPE type = TYPE::CONTROL;
	STATE state = STATE::UP;
	int velocity;
};