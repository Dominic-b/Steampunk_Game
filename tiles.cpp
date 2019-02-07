#include "stdafx.h"

void Tiles::mapInit(std::string path) {
	//Open the map
	std::ifstream map(path);

	int tileType;
	for (int i = 0; i < 12; i++) {
		for (int a = 0; a < 16; a++) {
			map >> tileType;
			tileGrid[a][i] = tileType;
		}
	}
}

void Tiles::textureInit(SDL_Renderer* renderer) {
	topLeft = draw.loadTexture("Images/topLeft.png", renderer);
	top = draw.loadTexture("Images/top.png", renderer);
	topRight = draw.loadTexture("Images/topRight.png", renderer);
	right = draw.loadTexture("Images/right.png", renderer);
	bottomRight = draw.loadTexture("Images/bottomRight.png", renderer);
	bottom = draw.loadTexture("Images/bottom.png", renderer);
	bottomLeft = draw.loadTexture("Images/bottomLeft.png", renderer);
	left = draw.loadTexture("Images/left.png", renderer);
	center = draw.loadTexture("Images/center.png", renderer);
}

void Tiles::drawTiles(int tileGrid[132][12], Object::Camera camera, SDL_Renderer* renderer) {
	SDL_Rect destination;
	destination.w = TILE_WIDTH;
	destination.h = TILE_HEIGHT;
	for (int i = 0; i < 132; i++) {
		for (int a = 0; a < 12; a++) {
			if (tileGrid[i][a] != 0 && i * TILE_WIDTH >= camera.x - TILE_WIDTH && i * TILE_WIDTH < camera.x + SCREEN_WIDTH) {
				destination.x = i * TILE_WIDTH - camera.x;
				destination.y = a * TILE_HEIGHT - camera.y;
				switch (tileGrid[i][a]) {
					case 1:
						SDL_RenderCopy(renderer, topLeft, nullptr, &destination);
						break;
					case 2:
						SDL_RenderCopy(renderer, top, nullptr, &destination);
						break;
					case 3:
						SDL_RenderCopy(renderer, topRight, nullptr, &destination);
						break;
					case 4:
						SDL_RenderCopy(renderer, right, nullptr, &destination);
						break;
					case 5:
						SDL_RenderCopy(renderer, bottomRight, nullptr, &destination);
						break;
					case 6:
						SDL_RenderCopy(renderer, bottom, nullptr, &destination);
						break;
					case 7:
						SDL_RenderCopy(renderer, bottomLeft, nullptr, &destination);
						break;
					case 8:
						SDL_RenderCopy(renderer, left, nullptr, &destination);
						break;
					case 9:
						SDL_RenderCopy(renderer, center, nullptr, &destination);
						break;
				}
			}
		}
	}
}

void Tiles::checkCollision(int tileGrid[132][12], Object::Player &a) {
	for (int i = 0; i < 132; i++) {
		for (int e = 0; e < 12; e++) {
			if (tileGrid[i][e] != 0 && tileGrid[i][e] != 9) {
				if (a.x + a.hitbox.width / 2 > i * TILE_WIDTH && a.x - a.hitbox.width / 2 < i * TILE_WIDTH + TILE_WIDTH && a.y + a.hitbox.height / 2 > e * TILE_HEIGHT && a.y - a.hitbox.height / 2 < e * TILE_HEIGHT + TILE_HEIGHT) {
					switch (tileGrid[i][e]) {
					case 1://topleft
						if (i * TILE_WIDTH - a.x < e * TILE_HEIGHT - a.y) {
							a.y = e * TILE_HEIGHT - a.hitbox.height / 2;
							a.velY = 0;
							a.airborne = false;
						} else {
							a.x = i * TILE_WIDTH - a.hitbox.width / 2;
							a.velX = 0;
						}
						break;
					case 2://top
						a.y = e * TILE_HEIGHT - a.hitbox.height / 2;
						a.velY = 0;
						a.airborne = false;
						break;
					case 3://topright
						if (i * TILE_WIDTH + TILE_WIDTH + a.x < e * TILE_HEIGHT - a.y) {
							a.x = i * TILE_WIDTH + TILE_WIDTH - a.hitbox.width - a.hitbox.width / 2;
							a.velX = 0;
						} else {
							a.y = e * TILE_HEIGHT - a.hitbox.height / 2;
							a.velY = 0;
							a.airborne = false;
						}
						break;
					case 4://right
						a.x = i * TILE_WIDTH + TILE_WIDTH + a.hitbox.width - a.hitbox.width / 2;
						a.velX = 0;
						break;
					case 5://bottomright
						if (i * TILE_WIDTH + TILE_WIDTH - a.x < e * TILE_HEIGHT + TILE_HEIGHT - a.y) {
							a.x = i * TILE_WIDTH + TILE_WIDTH + a.hitbox.width - a.hitbox.width / 2;
							a.velX = 0;
						}
						else {
							a.y = e * TILE_HEIGHT + TILE_HEIGHT + a.hitbox.height - a.hitbox.height / 2;
							a.velY = 0;
						}
						break;
					case 6://bottom
						a.y = e * TILE_HEIGHT + TILE_HEIGHT + a.hitbox.height - a.hitbox.height / 2;
						a.velY = 0;
						break;
					case 7://bottomleft
						if (i * TILE_WIDTH - a.x < e * TILE_HEIGHT + TILE_HEIGHT - a.y) {
							a.x = i * TILE_WIDTH - a.hitbox.width / 2;
							a.velX = 0;
						} else {
							a.y = e * TILE_HEIGHT + TILE_HEIGHT + a.hitbox.height / 2;
							a.velY = 0;
						}
						break;
					case 8://left
						a.x = i * TILE_WIDTH - a.hitbox.width / 2;
						a.velX = 0;
						break;
					}
				}
			}
		}
	}
}