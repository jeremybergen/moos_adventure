#include <iostream>
#include <vector>
#include <string>
#include "mooGame.h"

#define DEBUG(s) std::cerr << s << std::endl;
int no = 0;

void games::mooGame::setup() {
	//sprites::Sprites back = new sprites::Sprites();
	sprites::Sprites *back = new sprites::Sprites();
	//sprites::Sprites *controls = new sprites::Controls();
	//sprites::Sprites *character = new sprites::Sprites();
	
	//std::vector<sprites::Controls *> controls;
	//std::vector<sprites::Sprites *> character;
	back->init(this, "img\\back", 1);
	//back->init(this, "ctrl_", 2);
	back->setup();
	add("back0",back);
	//elements.insert({ "back0", back });

	sprites::Sprites *moo = new sprites::Sprites();
	moo->init(this, "img\\moo", 4, 0, 0, 0, 0, 25.0, 150.0, 0);
	moo->setup();
	add("moo0",moo);
	character.push_back(moo);

	/* sprites::Sprites *box = new sprites::Sprites();
	box->init(this, "img\\box", 1, 0, 0, 0, 0, 25.0, 150.0, 0);
	box->setup();
	add("box0", box);

	sprites::Sprites *box2 = new sprites::Sprites();
	box2->init(this, "img\\box", 1, 0, 0, 0, 0, 75.0, 150.0, 0);
	box2->setup();
	add("box1", box2);

	sprites::Sprites *box3 = new sprites::Sprites();
	box3->init(this, "img\\box", 1, 0, 0, 0, 0, 125.0, 150.0, 0);
	box3->setup();
	add("box2", box3);

	sprites::Sprites *mouse = new sprites::Sprites();
	mouse->init(this, "img\\mouse", 4, 0, 0, 0, 0, 125.0, 150.0, 0);
	mouse->setup();
	add("mouse0", mouse);

	sprites::Sprites *key = new sprites::Sprites();
	key->init(this, "img\\key", 4, 0, 0, 0, 0, 75.0, 150.0, 0);
	key->setup();
	add("key0", key); */

}

void games::mooGame::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_ESCAPE) {
			setDone(true);
		}
		if (e.key.keysym.sym == SDLK_LEFT) {
			//DEBUG("pressed left key");
			addControl("img\\ctrl_left", 1);
		}
		if (e.key.keysym.sym == SDLK_RIGHT) {
			addControl("img\\ctrl_right", 2);
		}
		if (e.key.keysym.sym == SDLK_UP) {
			addControl("img\\ctrl_up", 3);
		}
		if (e.key.keysym.sym == SDLK_DOWN) {
			addControl("img\\ctrl_down", 4);
		}
		if (e.key.keysym.sym == SDLK_RETURN) {
			addControl("img\\ctrl_pick_drop", 5);
		}
		if (e.key.keysym.sym == SDLK_SPACE) {
			evalControls();
			no = 0;
		}
	}
}

void games::mooGame::addControl(std::string newFilename, int action) {
	//DEBUG(games::mooGame::character.size());
	DEBUG("adding control");
	std::string ncntl = "cntl" + std::to_string(controls.size());
	sprites::Controls *ctrl = new sprites::Controls();
	int pY = 50 + 25 * controls.size();
	ctrl->init(this, newFilename, 1, 0, 0, 0, 0, 505.0, pY, 0, action);
	ctrl->setup();
	add(ncntl, ctrl);
	//add(ctrl);
	controls.push_back(ctrl);
	//elements.insert({ ncntl, ctrl });
}

std::vector<sprites::Sprites *> games::mooGame::getCharacter() {
	return character;
}

void games::mooGame::evalControls() {
	while (controls.size() > 0) {
		DEBUG(controls[0]->getAction());
		switch (controls[0]->getAction()) {
		case 1:
			character[0]->moveCharacter(character[0]->getPx() - 50, character[0]->getPy(), character[0], no);
			no++;
			break;
		case 2:
			character[0]->moveCharacter(character[0]->getPx() + 50, character[0]->getPy(), character[0], no);
			no++;
			break;
		case 3:
			character[0]->moveCharacter(character[0]->getPx(), character[0]->getPy() - 50, character[0], no);
			no++;
			break;
		case 4:
			character[0]->moveCharacter(character[0]->getPx(), character[0]->getPy() + 50, character[0], no);
			no++;
			break;
		case 5:
			break;
		default:
			break;
		}
		std::cout << "" << std::endl;
		controls.erase(controls.begin());
		//elements.erase("cntl" + no);
		games::Game::remove("cntl" + std::to_string((no - 1)));
		//no--;
	}
}

void games::mooGame::cleanup() {

}