#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <sstream>
#include <iterator>

#include "mooGame.h"

#define DEBUG(s) std::cerr << s << std::endl;


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
	add(back);

	sprites::Sprites *moo = new sprites::Sprites();
	moo->init(this, "img\\moo", 1, 0, 0, 0, 0, 25.0, 150.0, 0);
	moo->setup();
	add(moo);
	character.push_back(moo);
	
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
		}
	}
}

void games::mooGame::addControl(std::string newFilename, int action) {
	DEBUG(games::mooGame::character.size());
	DEBUG("adding control");
	sprites::Controls *ctrl = new sprites::Controls();
	int pY = 50 + 25 * controls.size();
	ctrl->init(this, newFilename, 1, 0, 0, 0, 0, 505.0, pY, 0, action);
	ctrl->setup();
	add(ctrl);
	controls.push_back(ctrl);
}

void games::mooGame::evalControls() {
	int i = 0;
	while (controls.size() > 0) {
		DEBUG(controls[0]->getAction());
		switch (controls[0]->getAction()) {
		case 1:
			character[0]->moveCharacter(character[0]->getPx() - 50, character[0]->getPy());
			break;
		case 2:
			character[0]->moveCharacter(character[0]->getPx() + 50, character[0]->getPy());
			break;
		case 3:
			character[0]->moveCharacter(character[0]->getPx(), character[0]->getPy() - 50);
			break;
		case 4:
			character[0]->moveCharacter(character[0]->getPx(), character[0]->getPy() + 50);
			break;
		case 5:
			break;
		default:
			break;
		}
		controls.erase(controls.begin());
	}
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