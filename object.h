#pragma once
#include "stdafx.h"

class Object {
	
	public:
		//camera object
		struct Camera {
			int x, y;
			SDL_Rect camera;

			Camera();
		};

		struct Point {
			float x, y;

			Point();
		};
		void drawPoint(Point a, Camera b, SDL_Renderer* renderer);

		struct Line {
			Point *a, *b;

			Line();
		};

		struct AABB {//Axis-Alligned Bounding Box
			int x, y;
			int width, height;

			AABB();
		};

		struct Player {
			AABB hitbox;
			float x, y;
			float velX, velY;
			float forceX, forceY;

			float maxSpeed;
			float acceleration;

			bool airborne;
			
			Player();
		};
		void drawPlayer(Player a, Camera b, SDL_Renderer* renderer);
};