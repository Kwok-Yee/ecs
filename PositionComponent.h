#pragma once
#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent() {}
	float getXPosition() { return x; }
	float getYPosition() { return y; }
	void setXPosition(float a) { x = a; }
	void setYPosition(float b) { y = b; }
private:
	float x;
	float y;
};