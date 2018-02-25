#include <iostream>
#include <vector>
#include "mooGame.h"

#define DEBUG(s) std::cerr << s << std::endl;


void games::mooGame::setup() {
	//sprites::Sprites back = new sprites::Sprites();
	sprites::Sprites *back = new sprites::Sprites();
	//sprites::Sprites *controls = new sprites::Controls();
	std::vector<sprites::Controls *> controls;
	back->init(this, "img\\back", 1);
	//back->init(this, "ctrl_", 2);
	back->setup();
	add(back);
}

void games::mooGame::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_ESCAPE) {
			setDone(true);
		}
		if (e.key.keysym.sym == SDLK_LEFT) {
			//DEBUG("pressed left key");
			addControl("img\\ctrl_left");
		}
		if (e.key.keysym.sym == SDLK_RIGHT) {
			addControl("img\\ctrl_right");
		}
		if (e.key.keysym.sym == SDLK_UP) {
			addControl("img\\ctrl_up");
		}
		if (e.key.keysym.sym == SDLK_DOWN) {
			addControl("img\\ctrl_down");
		}
		if (e.key.keysym.sym == SDLK_RETURN) {
			addControl("img\\ctrl_pick_drop");
		}
	}
}

void games::mooGame::addControl(std::string newFilename) {
	DEBUG("adding control");
	sprites::Controls *ctrl = new sprites::Controls();
	int pY = 50 + 25 * controls.size();
	ctrl->init(this, newFilename, 1, 0, 0, 0, 0, 505.0, pY, 0);
	ctrl->setup();
	add(ctrl);
	controls.push_back(ctrl);
}

void games::mooGame::cleanup() {

}