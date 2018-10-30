#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class HealthSystem
{
	vector<Entity> entities;
public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update()
	{
		for (size_t i = 0; i < entities.size(); i++)
		{
			cout << "HealthSystem Updating Entity with name: " << entities[i].getName() << endl;
		}
	}
};