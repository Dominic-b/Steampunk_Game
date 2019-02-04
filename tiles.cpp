#include "stdafx.h"

void Tiles::drawTiles(int tileGrid[132][12], Object::Camera camera, SDL_Renderer* renderer) {
	for (int i = 0; i < 132; i++) {
		for (int a = 0; a < 12; a++) {
			if (tileGrid[i][a] != 0) {
				SDL_Rect destination;
				destination.w = TILE_WIDTH;
				destination.h = TILE_HEIGHT;
				destination.x = i * TILE_WIDTH - camera.x;
				destination.y = a * TILE_HEIGHT - camera.y;
				switch (tileGrid[i][a]) {
					case 1:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/topLeft.png", renderer), nullptr, &destination);
						break;
					case 2:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/top.png", renderer), nullptr, &destination);
						break;
					case 3:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/topRight.png", renderer), nullptr, &destination);
						break;
					case 4:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/right.png", renderer), nullptr, &destination);
						break;
					case 5:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/bottomRight.png", renderer), nullptr, &destination);
						break;
					case 6:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/bottom.png", renderer), nullptr, &destination);
						break;
					case 7:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/bottomLeft.png", renderer), nullptr, &destination);
						break;
					case 8:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/left.png", renderer), nullptr, &destination);
						break;
					case 9:
						SDL_RenderCopy(renderer, draw.loadTexture("Images/center.png", renderer), nullptr, &destination);
						break;
				}
			}
		}
	}
}

void Tiles::checkCollision(int tileGrid[132][12], Object::Player &a) {
	for (int i = 0; i < 132; i++) {
		for (int e = 0; e < 12; e++) {
			if (tileGrid[i][e] != 0) {
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
						}
						else {
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