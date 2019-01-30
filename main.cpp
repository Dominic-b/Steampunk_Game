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
	hook.x = 300;
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
		object.drawPlayer(player, camera, renderer);
		object.drawPoint(hook, renderer);

		SDL_RenderPresent(renderer);
	}
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	return 0;
}