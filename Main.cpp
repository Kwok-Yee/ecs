#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <iostream>
#include <vector>
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"
#include "HealthSystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "AISystem.h"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main()
{
	Entity* player = new Entity("Player");
	Entity* alien = new Entity("Alien");
	Entity* dog = new Entity("Dog");
	Entity* cat = new Entity("Cat");

	player->addComponent(new HealthComponent(200));

	//alien.addComponent(healthComponent);
	//dog.addComponent(healthComponent);
	//cat.addComponent(healthComponent);

	//PositionComponent positionComponent;
	//player.addComponent(positionComponent);
	//alien.addComponent(positionComponent);
	//dog.addComponent(positionComponent);
	//cat.addComponent(positionComponent);

	//ControlComponent controlComponent;
	//player.addComponent(controlComponent);

	HealthSystem healthSystem;
	healthSystem.addEntity(player);
	//healthSystem.addEntity(alien);
	//healthSystem.addEntity(dog);
	//healthSystem.addEntity(cat);

	//ControlSystem controlSystem;
	//controlSystem.addEntity(player);
	//controlSystem.addEntity(alien);
	//controlSystem.addEntity(dog);
	//controlSystem.addEntity(cat);

	//RenderSystem renderSystem;
	//renderSystem.addEntity(player);
	//renderSystem.addEntity(alien);
	//renderSystem.addEntity(dog);
	//renderSystem.addEntity(cat);

	//AISystem aiSystem;
	//aiSystem.addEntity(alien);
	//aiSystem.addEntity(dog);
	//aiSystem.addEntity(cat);


	while (true)
	{
		healthSystem.update();
		//controlSystem.update();
		//renderSystem.update();
		//aiSystem.update();

	}

	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		SDL_SetMainReady();

		bool quit = false;

		SDL_Event event;

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
				
				//Apply the image
				SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	return 0;
}