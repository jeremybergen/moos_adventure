#include "game.h"

void games::Game::add(sprites::Sprites *s) {
	sprites.push_back(s);
}

void games::Game::addCtrl(sprites::Sprites *s) {
	controls.push_back(s);
} 

void games::Game::removeCtrl() {
	controls.erase(controls.begin());
}

void games::Game::loop(float dt) {
	for (unsigned int i = 0; i < sprites.size(); i++) {
		sprites[i]->loop(dt);
	}
	for (unsigned int i = 0; i < sprites.size(); i++) {
		sprites[i]->render();
	}
	for (unsigned int i = 0; i < controls.size(); i++) {
		controls[i]->loop(dt);
	}
	for (unsigned int i = 0; i < controls.size(); i++) {
		controls[i]->render();
	}
}