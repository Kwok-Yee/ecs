#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class RenderSystem
{

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void render(SDL_Renderer* renderer)
	{
		for (Entity* e : entities)
		{
			vector<Component*> components = e->getComponents();
			for (Component* c : components)
			{
				SDL_Rect srcRect;
				SDL_Rect dstRect;
				if (c->getType() == TYPE::POSITION)
				{
					PositionComponent* positionComponent = static_cast<PositionComponent*>(c);
					//cout << "RenderSystem, Entity: " << e->getName() << ", position: " << positionComponent->getXPosition() << ", " << positionComponent->getYPosition() << endl; cout << endl;
					srcRect = { 0 , 0, 32, 32 };
					dstRect = { positionComponent->getXPosition() , positionComponent->getYPosition(), 64, 64 };
				}
				if (c->getType() == TYPE::RENDER)
				{
					RenderComponent* renderComponent = static_cast<RenderComponent*>(c);
					SDL_RenderCopy(renderer, renderComponent->getTexture(), &srcRect, &dstRect);
					SDL_RenderPresent(renderer);
				}
			}
		}
	}
private:
	vector<Entity*> entities;

};