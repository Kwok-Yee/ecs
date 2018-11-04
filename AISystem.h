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
					//cout << "AISystem, Entity: " << e->getName() << ", velocity: " << aiComponent->getVelocity() << endl;
					velocity = aiComponent->getVelocity();
				}
				if (c->getType() == TYPE::POSITION)
				{
					PositionComponent* positionComponent = static_cast<PositionComponent*>(c);
					//cout << e->getName() << " velocity: " << velocity << endl;
					if (positionComponent->getXPosition() > 0 && positionComponent->getXPosition() < SCREEN_WIDTH)
					{
						velocity += positionComponent->getXPosition();
					}
					else if (positionComponent->getXPosition() < 0 && positionComponent->getXPosition() > SCREEN_WIDTH)
					{
						velocity -= positionComponent->getXPosition();
					}
					cout << velocity << endl;
					positionComponent->setXPosition(velocity);
				}
			}
		}
	}
private:
	vector<Entity*> entities;
	int velocity = 0;
};