#pragma once
#include <iostream>
#include <ctime>
#include "gameSetup.h"

int games::GameSetup::getMaxX() {
	return maxX;
}

int games::GameSetup::getMaxY() {
	return maxY;
}

SDL_Renderer *games::GameSetup::getRenderer() {
	return games::GameSetup::renderer;
}

void games::GameSetup::init(std::string WindowName = "Moo's Adventure", int newMaxX = 640, int newMaxY = 480) {
	maxX = newMaxX;
	maxY = newMaxY;
	done = false;
	dead = false;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, maxX, maxY, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		std::cout << "Could not open window: " << SDL_GetError() << std::endl;
		done = true;
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		std::cout << "Could not create render: " << SDL_GetError() << std::endl;
	}
	srand(time(NULL));
}

void games::GameSetup::run() {
	setup();
	float last = SDL_GetTicks();
	bool dead = false;
	while (!dead && !done) {
		SDL_Event event;
		float dt = ((float)SDL_GetTicks() - last) / 1000.0;
		last = SDL_GetTicks();
		loop(dt);
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)) {
			eventHandler(event);
		}
		SDL_Delay(1000 / 60);
	}
	if (!done) {
		games::GameSetup::cleanup();
	}
}

void games::GameSetup::exit() {
	if (done) return;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}