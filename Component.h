#pragma once

enum TYPE
{
	HEALTH,
	POSITION,
	CONTROL,
	RENDER,
	AI
};

class Component
{
public:
	Component() {};
	virtual TYPE getType() = 0;
};