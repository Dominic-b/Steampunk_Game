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
	SDL_RenderDrawPoint(renderer, a.x - b.x, a.y - b.y);
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

	maxSpeed = 15;
	acceleration = 1;

	airborne = true;
}

void Object::drawPlayer(Player a, Camera b, SDL_Renderer* renderer) {
	SDL_RenderDrawLine(renderer, a.hitbox.x - a.hitbox.width / 2 - b.x, a.hitbox.y - a.hitbox.height / 2 - b.y, a.hitbox.x + a.hitbox.width / 2 - b.x, a.hitbox.y - a.hitbox.height / 2 - b.y);
	SDL_RenderDrawLine(renderer, a.hitbox.x + a.hitbox.width / 2 - b.x, a.hitbox.y - a.hitbox.height / 2 - b.y, a.hitbox.x + a.hitbox.width / 2 - b.x, a.hitbox.y + a.hitbox.height / 2 - b.y);
	SDL_RenderDrawLine(renderer, a.hitbox.x + a.hitbox.width / 2 - b.x, a.hitbox.y + a.hitbox.height / 2 - b.y, a.hitbox.x - a.hitbox.width / 2 - b.x, a.hitbox.y + a.hitbox.height / 2 - b.y);
	SDL_RenderDrawLine(renderer, a.hitbox.x - a.hitbox.width / 2 - b.x, a.hitbox.y + a.hitbox.height / 2 - b.y, a.hitbox.x - a.hitbox.width / 2 - b.x, a.hitbox.y - a.hitbox.height / 2 - b.y);
}