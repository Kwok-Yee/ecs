#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class AISystem
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
				if (c->getType() == TYPE::AI)
				{
					AIComponent* aiComponent = static_cast<AIComponent*>(c);
					cout << "AISystem, Entity: " << e->getName() << ", is AI: " << aiComponent->getIsAI() << endl;
				}
			}
		}
		cout << endl;
	}
private:
	vector<Entity*> entities;
};