#include "stdafx.h"

void Move::moveCamera(Object::Camera &a, Object::Player b) {
	a.x = (b.x + b.hitbox.width / 2) - SCREEN_WIDTH / 2;
	a.y = (b.y + b.hitbox.height / 2) - SCREEN_HEIGHT / 2;

	if (a.x < 0) a.x = 0;
	else if (a.x + SCREEN_WIDTH > LEVEL_WIDTH) a.x = LEVEL_WIDTH - SCREEN_WIDTH;
	if (a.y < 0) a.y = 0;
	else if (a.y + SCREEN_HEIGHT > LEVEL_HEIGHT) a.y = LEVEL_HEIGHT - SCREEN_HEIGHT;
}

void Move::movePlayer(Object::Player &a, SDL_Event& e) {
	
	a.velX += a.forceX;
	a.velY += a.forceY;
	if (a.velX > a.maxSpeed) a.velX = a.maxSpeed;
	if (a.velX < -a.maxSpeed) a.velX = -a.maxSpeed;
	//if (a.velY > a.maxSpeed) a.velY = a.maxSpeed;
	//if (a.velY < -a.maxSpeed) a.velY = -a.maxSpeed;

	a.x += a.velX;
	a.y += a.velY;

	a.hitbox.x = a.x;
	a.hitbox.y = a.y;

	if (a.hitbox.y + (a.hitbox.height / 2) >= SCREEN_HEIGHT) {
		a.y = SCREEN_HEIGHT - (a.hitbox.height / 2) - 1;
		a.velY = 0;
		a.velX *= .9;
		a.airborne = false;
	} else {
		a.airborne = true;
	}

	a.forceX = 0;
	a.forceY = Gravity;

	//key presses
	SDL_PollEvent(&e);
	event.keyboard_state_array = SDL_GetKeyboardState(NULL);

	if (event.keyboard_state_array[SDL_SCANCODE_A]) a.forceX -= a.acceleration;
	if (event.keyboard_state_array[SDL_SCANCODE_D]) a.forceX += a.acceleration;
	if (event.keyboard_state_array[SDL_SCANCODE_SPACE] && !a.airborne) a.forceY -= 25;

}

void Move::moveHook(Object::Player &a, Object::Point b) {
	float distance = pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
	a.forceX -= ((a.x - b.x) / distance) * (distance) * (float).025;
	a.forceY -= ((a.y - b.y) / distance) * (distance) * (float).025;

	a.forceX -= a.velX * (float).01;
	a.forceY -= a.velY * (float).01;
}
