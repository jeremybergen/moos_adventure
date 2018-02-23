#include "game.h"

void games::Game::add(sprites::Sprites *s) {
	sprites.push_back(s);
}

void games::Game::loop(float dt) {
	for (unsigned int i = 0; i < sprites.size(); i++) {
		sprites[i]->loop(dt);
	}
	for (unsigned int i = 0; i < sprites.size(); i++) {
		sprites[i]->render();
	}
}