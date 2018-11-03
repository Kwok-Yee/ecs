#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class RenderSystem
{

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void update()
	{
		cout << "RenderSystem" << endl;
		for (Entity* e : entities)
		{
			vector<Component*> components = e->getComponents();
			for (Component* c : components)
			{
				if (c->getType() == TYPE::POSITION)
				{
					PositionComponent* positionComponent = static_cast<PositionComponent*>(c);
					cout << "Entity: " << e->getName() << ", position: " << positionComponent->getXPosition() << ", " << positionComponent->getYPosition() << endl;
				}
			}
		}
		cout << endl;
	}
private:
	vector<Entity*> entities;
};