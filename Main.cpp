#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"
#include "AIComponent.h"
#include "RenderComponent.h"
#include "HealthSystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "AISystem.h"

using namespace std;

int main()
{
	RenderSystem renderSystem;
	renderSystem.init();

	SDL_Event event;

	Entity* player = new Entity("Player");
	Entity* alien = new Entity("Alien");
	Entity* dog = new Entity("Dog");
	Entity* cat = new Entity("Cat");

	player->addComponent(new HealthComponent(200));
	player->addComponent(new PositionComponent(10, 30));
	player->addComponent(new ControlComponent(5));
	player->addComponent(new RenderComponent(SDL_CreateTextureFromSurface(renderer, IMG_Load("player.png"))));

	alien->addComponent(new HealthComponent(150));
	alien->addComponent(new PositionComponent(10, 180));
	alien->addComponent(new AIComponent(2));
	alien->addComponent(new RenderComponent(SDL_CreateTextureFromSurface(renderer, IMG_Load("alien.png"))));

	dog->addComponent(new HealthComponent(100));
	dog->addComponent(new PositionComponent(10, 320));
	dog->addComponent(new AIComponent(1));
	dog->addComponent(new RenderComponent(SDL_CreateTextureFromSurface(renderer, IMG_Load("dog.png"))));

	cat->addComponent(new HealthComponent(75));
	cat->addComponent(new PositionComponent(10, 470));
	cat->addComponent(new AIComponent(1));
	cat->addComponent(new RenderComponent(SDL_CreateTextureFromSurface(renderer, IMG_Load("cat.png"))));

	HealthSystem healthSystem;
	healthSystem.addEntity(player);
	healthSystem.addEntity(alien);
	healthSystem.addEntity(dog);
	healthSystem.addEntity(cat);

	ControlSystem controlSystem;
	controlSystem.addEntity(player);

	renderSystem.addEntity(player);
	renderSystem.addEntity(alien);
	renderSystem.addEntity(dog);
	renderSystem.addEntity(cat);

	AISystem aiSystem;
	aiSystem.addEntity(alien);
	aiSystem.addEntity(dog);
	aiSystem.addEntity(cat);

	while (!renderSystem.getisQuit())
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				renderSystem.setIsQuit(true);
				renderSystem.quit();
			}
			else if (event.type == SDL_KEYDOWN)
			{
				controlSystem.update(event);
			}
		}
		healthSystem.update();
		aiSystem.update();
		renderSystem.render(renderer);
	}
	return 0;
}