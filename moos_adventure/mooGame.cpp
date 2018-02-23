#include <iostream>

#include "mooGame.h"

void games::mooGame::setup() {
	//sprites::Sprites back = new sprites::Sprites();
	sprites::Sprites *back = new sprites::Sprites();
	back->init(this, "back", 1);
	back->setup();
	add(back);
}

void games::mooGame::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_ESCAPE) {
			setDone(true);
		}
	}
}

void games::mooGame::cleanup() {

}