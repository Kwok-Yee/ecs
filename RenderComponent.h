#pragma once
#include "Component.h"

class RenderComponent : public Component
{
public:
	RenderComponent(SDL_Texture* t) { texture = t; }
	SDL_Texture* getTexture() { return texture; }
	TYPE getType() { return type; }
private:
	TYPE type = TYPE::RENDER;
	SDL_Texture* texture;
};