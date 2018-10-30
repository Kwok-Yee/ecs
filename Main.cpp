#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <iostream>
#include "Entity.h"
#include "HealthComponent.h"
#include "HealthSystem.h"

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
	Entity player = Entity("Player");
	Entity alien = Entity("Alien");
	Entity dog = Entity("Dog");
	Entity cat = Entity("Cat");

	HealthComponent healthComponent;
	player.addComponent(healthComponent);
	alien.addComponent(healthComponent);
	dog.addComponent(healthComponent);
	cat.addComponent(healthComponent);

	HealthSystem healthSystem;
	healthSystem.addEntity(player);
	healthSystem.addEntity(alien);
	healthSystem.addEntity(dog);
	healthSystem.addEntity(cat);

	while (true)
	{
		healthSystem.update();
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