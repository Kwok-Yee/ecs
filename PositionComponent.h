#pragma once
#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent(int a, int b) { x = a; y = b; }
	int getXPosition() { return x; }
	int getYPosition() { return y; }
	void setXPosition(int a) { x = a; }
	void setYPosition(int b) { y = b; }
	TYPE getType() { return type; }
private:
	TYPE type = TYPE::POSITION;
	int x;
	int y;
};