#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class ControlSystem
{

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void update(SDL_Event& event)
	{
		move(event);
		for (Entity* e : entities)
		{
			vector<Component*> components = e->getComponents();
			for (Component* c : components)
			{
				if (c->getType() == TYPE::POSITION)
				{
					positionComponent = static_cast<PositionComponent*>(c);
				}
				if (c->getType() == TYPE::CONTROL)
				{
					controlComponent = static_cast<ControlComponent*>(c);
					switch (controlComponent->getState())
					{
					case STATE::UP:
						yVelocity = positionComponent->getYPosition() + -(controlComponent->getVelocity());
						break;
					case STATE::DOWN:
						yVelocity = positionComponent->getYPosition() + controlComponent->getVelocity();
						break;
					case STATE::LEFT:
						xVelocity = positionComponent->getXPosition() + -(controlComponent->getVelocity());
						break;
					case STATE::RIGHT:
						xVelocity = positionComponent->getXPosition() + controlComponent->getVelocity();
						break;
					}
					positionComponent->setXPosition(xVelocity);
					positionComponent->setYPosition(yVelocity);
				}
			}
		}
	}
	void move(SDL_Event &event)
	{
		for (Entity* e : entities)
		{
			vector<Component*> components = e->getComponents();
			for (Component* c : components)
			{
				if (c->getType() == TYPE::CONTROL)
				{
					controlComponent = static_cast<ControlComponent*>(c);
					switch (event.key.keysym.sym)
					{
					case SDLK_w:
						controlComponent->setState(STATE::UP);
						break;
					case SDLK_a:
						controlComponent->setState(STATE::LEFT);
						break;
					case SDLK_s:
						controlComponent->setState(STATE::DOWN);
						break;
					case SDLK_d:
						controlComponent->setState(STATE::RIGHT);
						break;
					}
				}
			}
		}
	}
private:
	vector<Entity*> entities;
	PositionComponent* positionComponent;
	ControlComponent* controlComponent;
	int xVelocity = 0;
	int yVelocity = 0;
};