#include "stdafx.h"

int main(int argc, char args[]) {
	SDL_Texture* texture = nullptr;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	SDL_Window* window = SDL_CreateWindow("SDL Testing things", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);// add in " | SDL_RENDERER_PRESENTVSYNC" after SDL_RENDERER_ACCELERATED for vsync
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_Event e;

	Object::Camera camera;

	Object::Point hook;
	hook.x = 1500;
	hook.y = 100;

	Object::Player player;
	player.hitbox.width = 50;
	player.hitbox.height = 50;

	while (!event.quit) {//game loop
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

		event.update(e);
		move.movePlayer(player, e);
		if (event.mouse1held) move.moveHook(player, hook);

		move.moveCamera(camera, player);
		object.drawPoint(hook, camera, renderer);
		object.drawPlayer(player, camera, renderer);


		SDL_RenderDrawLine(renderer, 0 - camera.x, 100 - camera.y, 3000 - camera.x, 400 - camera.y);

		SDL_RenderPresent(renderer);
	}
	draw.free();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	return 0;
}