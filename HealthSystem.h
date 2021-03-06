#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class HealthSystem
{

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void update()
	{
		for (Entity* e : entities)
		{
			vector<Component*> components = e->getComponents();
			for (Component* c : components)
			{
				if (c->getType() == TYPE::HEALTH)
				{
					HealthComponent* healthComponent = static_cast<HealthComponent*>(c);
					//cout << "HealthSystem, Entity: " << e->getName() << ", Health: " << healthComponent->getHealth() << endl; cout << endl;
				}
			}
		}
	}
private:
	vector<Entity*> entities;
};