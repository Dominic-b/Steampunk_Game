#pragma once
#include "stdafx.h"

class Move {
	public:
		void moveCamera(Object::Camera &a, Object::Player b);
		void movePlayer(Object::Player &a, SDL_Event& e);
		void moveHook(Object::Player &a, Object::Point b);
};