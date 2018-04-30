#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

#include <string>
#include "mooGame.h"

#define DEBUG(s) std::cerr << s << std::endl;
int no = 0;

template<typename Out>
void moosplit(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> moosplit(const std::string &s, char delim) {
	std::vector<std::string> elems;
	moosplit(s, delim, std::back_inserter(elems));
	return elems;
}

void games::mooGame::setup() {

	map();
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

	sprites::Sprites *box = new sprites::Sprites();
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
	add("key0", key);

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
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		//400,414  :  450, 414   :   142, 462   :   93, 462
		std::cout << e.motion.x << "," << e.motion.y << std::endl;
		if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 15 && e.motion.x < 65)
			addControl("img\\ctrl_right", 2);
		else if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 93 && e.motion.x < 142)
			addControl("img\\ctrl_left", 1);
		else if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 170&& e.motion.x < 218)
			addControl("img\\ctrl_up", 3);
		else if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 250 && e.motion.x < 300)
			addControl("img\\ctrl_down", 4);
		else if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 330 && e.motion.x < 380)
			addControl("img\\ctrl_pick_drop", 5);
		if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 400 && e.motion.x < 450) {
			evalControls();
			no = 0;
		}

		int square = -1;
		//int temp;
		if (e.motion.y > 45 && e.motion.y < 375 && e.motion.x > 500 && e.motion.x < 560) {
			square = (e.motion.y - 45) / 25;
			std::cout << "Square: " << square << std::endl;
			if (square < controls.size()) {
				controls.erase(controls.begin() + square);
				std::cout << "ControlSize: " << controls.size() << std::endl;
				if (square != controls.size()) {
					for (int i = square; i < controls.size(); i++) {
						swapE("cntl" + std::to_string(i), "cntl" + std::to_string(i + 1));
						controls.at(i)->setPy(50 + 25 * i);
						//temp = i;
					}
				}
				games::Game::remove("cntl" + std::to_string((controls.size())));
				//no--;
				character[0]->update();
			}
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

void games::mooGame::addPControl(std::string newFilename, int action) {
	//DEBUG(games::mooGame::character.size());
	DEBUG("adding pControl");
	std::string ncntl = "pCntl" + std::to_string(pControls.size());
	sprites::Controls *ctrl = new sprites::Controls();
	int pY = 50 + 25 * pControls.size();
	ctrl->init(this, newFilename, 1, 0, 0, 0, 0, 580.0, pY, 0, action);
	ctrl->setup();
	add(ncntl, ctrl);
	//add(ctrl);
	pControls.push_back(ctrl);
	//elements.insert({ ncntl, ctrl });
}


std::vector<sprites::Sprites *> games::mooGame::getCharacter() {
	return character;
}

void games::mooGame::evalControls() {
	int u = 0;
	if (pControls.size() != 0)
		while (pControls.size() > 0) {
			pControls.erase(pControls.begin());
			games::Game::remove("pCntl" + std::to_string(u));
			u++;
		}

	while (controls.size() > 0) {
		DEBUG(controls[0]->getAction());
		switch (controls[0]->getAction()) {
		case 1:
			character[0]->moveCharacter(character[0]->getPx() - 50, character[0]->getPy(), character[0], no);
			addPControl("img\\ctrl_left", 1);
			no++;
			break;
		case 2:
			character[0]->moveCharacter(character[0]->getPx() + 50, character[0]->getPy(), character[0], no);
			addPControl("img\\ctrl_right", 2);
			no++;
			break;
		case 3:
			character[0]->moveCharacter(character[0]->getPx(), character[0]->getPy() - 50, character[0], no);
			addPControl("img\\ctrl_up", 3);
			no++;
			break;
		case 4:
			character[0]->moveCharacter(character[0]->getPx(), character[0]->getPy() + 50, character[0], no);
			addPControl("img\\ctrl_down", 4);
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
	std::cout << "controls: " << controls.size() << std::endl;
}


void games::mooGame::map() // Nick
{
	std::ifstream is("Map.txt");
	std::string line;
	std::string tmp;
	//std::unordered_map<std::string,int>;
	std::vector<maps::Map> tokens;
	while (std::getline( is, line))
	{
		maps::Map mapLevel;

		std::stringstream iss(line);
		//iss >> tmp;
		std::vector<std::string> x = moosplit(line, ',');
		mapLevel.init(stoi(x[0]), stoi(x[1]), x[2]);
		tokens.push_back(mapLevel);
		std::cout << line << std::endl;
		//std::string token;// shouldent need token.
	}
	

	//std::cout << line; //Checking data
	

}


void games::mooGame::cleanup() {

}