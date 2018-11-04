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

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("Entity Component System", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Event event;
	bool quit = false;

	Entity* player = new Entity("Player");
	Entity* alien = new Entity("Alien");
	Entity* dog = new Entity("Dog");
	Entity* cat = new Entity("Cat");

	player->addComponent(new HealthComponent(200));
	player->addComponent(new PositionComponent(10, 30));
	player->addComponent(new ControlComponent());
	player->addComponent(new RenderComponent(SDL_CreateTextureFromSurface(renderer, IMG_Load("player.png"))));

	alien->addComponent(new HealthComponent(150));
	alien->addComponent(new PositionComponent(10, 180));
	alien->addComponent(new AIComponent());
	alien->addComponent(new RenderComponent(SDL_CreateTextureFromSurface(renderer, IMG_Load("alien.png"))));

	dog->addComponent(new HealthComponent(100));
	dog->addComponent(new PositionComponent(10, 320));
	dog->addComponent(new AIComponent());
	dog->addComponent(new RenderComponent(SDL_CreateTextureFromSurface(renderer, IMG_Load("dog.png"))));

	cat->addComponent(new HealthComponent(75));
	cat->addComponent(new PositionComponent(10, 470));
	cat->addComponent(new AIComponent());
	cat->addComponent(new RenderComponent(SDL_CreateTextureFromSurface(renderer, IMG_Load("cat.png"))));

	HealthSystem healthSystem;
	healthSystem.addEntity(player);
	healthSystem.addEntity(alien);
	healthSystem.addEntity(dog);
	healthSystem.addEntity(cat);

	ControlSystem controlSystem;
	controlSystem.addEntity(player);

	RenderSystem renderSystem;
	renderSystem.addEntity(player);
	renderSystem.addEntity(alien);
	renderSystem.addEntity(dog);
	renderSystem.addEntity(cat);

	AISystem aiSystem;
	aiSystem.addEntity(alien);
	aiSystem.addEntity(dog);
	aiSystem.addEntity(cat);

	healthSystem.update();
	controlSystem.update();
	aiSystem.update();
	renderSystem.render(renderer);

	// Set background color
	SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
	SDL_RenderClear(renderer);

	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN)
			{

			}
		}
		healthSystem.update();
		renderSystem.render(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}