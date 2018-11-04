#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// The window we'll be rendering to
SDL_Window* window = NULL;

// The surface image
SDL_Surface* image = NULL;

// The renderer
SDL_Renderer * renderer = NULL;

// The texture that will be created
SDL_Texture* texture = NULL;

class RenderSystem
{

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void init()
	{
		SDL_Init(SDL_INIT_VIDEO);
		IMG_Init(IMG_INIT_PNG);

		window = SDL_CreateWindow("Entity Component System", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);

		// Set background color
		SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
		SDL_RenderClear(renderer);
	}
	void quit()
	{
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(image);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		IMG_Quit();
		SDL_Quit();
	}
	void setIsQuit(bool b) { isQuit = b; };
	bool getisQuit() { return isQuit; };

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
					SDL_RenderClear(renderer);
					SDL_RenderCopy(renderer, renderComponent->getTexture(), &srcRect, &dstRect);
					SDL_RenderPresent(renderer);
				}
			}
		}
	}
private:
	vector<Entity*> entities;
	bool isQuit = false;
};