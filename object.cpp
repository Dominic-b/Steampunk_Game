#include "stdafx.h"

Object::Camera::Camera() {
	x = 0;
	y = 0;
	camera = { x, y, SCREEN_WIDTH, SCREEN_HEIGHT };
}

Object::Point::Point() {
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
}

void Object::drawPoint(Point a, Camera b, SDL_Renderer* renderer) {
	SDL_Rect destination;
	destination.x = a.x - 8 - b.x;
	destination.y = a.y - 8 - b.y;
	destination.w = 16;
	destination.h = 16;

	SDL_RenderCopy(renderer, draw.loadTexture("Images/Square.png", renderer), nullptr, &destination);
}

Object::Line::Line() {
	a = nullptr;
	b = nullptr;
}

Object::AABB::AABB() {
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	width = 0;
	height = 0;
}

Object::Player::Player() {
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	velX = 0;
	velY = 0;
	forceX = 0;
	forceY = Gravity;

	maxSpeed = 20;
	acceleration = 1;

	airborne = true;
}

void Object::drawPlayer(Player a, Camera b, SDL_Renderer* renderer) {
	SDL_Rect destination;
	destination.x = a.x - a.hitbox.width / 2 - b.x;
	destination.y = a.y - a.hitbox.height / 2 - b.y;
	destination.w = a.hitbox.width;
	destination.h = a.hitbox.height;

	SDL_RenderCopy(renderer, draw.loadTexture("Images/Square.png", renderer), nullptr, &destination);
}