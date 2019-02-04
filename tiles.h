#pragma once
#include "stdafx.h"

class Tiles {
public:
	void drawTiles(int tileGrid[132][12], Object::Camera camera, SDL_Renderer* renderer);

	void checkCollision(int tileGrid[132][12], Object::Player &a);

	int tileGrid[132][12];
};
