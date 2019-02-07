#pragma once
#include "stdafx.h"

class Tiles {
public:
	void mapInit(std::string path);
	void textureInit(SDL_Renderer* renderer);
	void drawTiles(int tileGrid[132][12], Object::Camera camera, SDL_Renderer* renderer);

	void checkCollision(int tileGrid[132][12], Object::Player &a);

	int tileGrid[132][12];

	SDL_Texture* topLeft;
	SDL_Texture* top;
	SDL_Texture* topRight;
	SDL_Texture* right;
	SDL_Texture* bottomRight;
	SDL_Texture* bottom;
	SDL_Texture* bottomLeft;
	SDL_Texture* left;
	SDL_Texture* center;
};
