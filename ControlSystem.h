#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class ControlSystem
{

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void update()
	{
		cout << "ControlSystem" << endl;
		for (Entity* e : entities)
		{
			vector<Component*> components = e->getComponents();
			for (Component* c : components)
			{
				if (c->getType() == TYPE::CONTROL)
				{
					ControlComponent* controlComponent = static_cast<ControlComponent*>(c);
					cout << "Entity: " << e->getName() << ", is Moving: " << controlComponent->getIsMoving() << endl;
				}
			}
		}
		cout << endl;
	}
private:
	vector<Entity*> entities;
};