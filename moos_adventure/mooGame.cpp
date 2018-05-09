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

	sprites::Sprites *splash = new sprites::Sprites();
	splash->init(this, "img\\splash", 1);
	splash->setup();
	add("splash0", splash);
	splashScreen = true;
	//Load music
	games::Game::gMusic = Mix_LoadMUS("382327__carpuzi__background-music-treatment.wav");
	if (games::Game::gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		//success = false;
	}
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(gMusic, -1);
	}

	games::Game::gMeow = Mix_LoadWAV("gMeow.wav");
	if (games::Game::gMeow == NULL)
	{
		printf("Failed to load meow sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		//success = false;
	}
	games::Game::gCry = Mix_LoadWAV("gCry.wav");
	if (games::Game::gCry == NULL)
	{
		printf("Failed to load cry sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		//success = false;
	}
}

void games::mooGame::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN && splashScreen != true) {
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
		if (splashScreen) {
			std::cout << e.motion.x << "," << e.motion.y << std::endl;
			if (e.motion.y > 200 && e.motion.y < 250 && e.motion.x > 170 && e.motion.x < 470) {
				games::GameSetup::scoreSetup();
				setupGame();
			}
			else if (e.motion.y > 268 && e.motion.y < 318 && e.motion.x > 170 && e.motion.x < 470)
				levelSelection();
			else if (e.motion.y > 339 && e.motion.y < 389 && e.motion.x > 170 && e.motion.x < 470)
				displayCredits();
			else if (e.motion.y > 409 && e.motion.y < 459 && e.motion.x > 170 && e.motion.x < 470)
				setDone(true);
		} else if (creditScreen) {
			if (e.motion.y > 373 && e.motion.y < 423 && e.motion.x > 170 && e.motion.x < 470) {
				games::Game::remove("credits0");
				displaySplash();
			}
		}else {
			std::cout << e.motion.x << "," << e.motion.y << std::endl;
			if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 15 && e.motion.x < 65)
				addControl("img\\ctrl_right", 2);
			else if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 93 && e.motion.x < 142)
				addControl("img\\ctrl_left", 1);
			else if (e.motion.y > 415 && e.motion.y < 460 && e.motion.x > 170 && e.motion.x < 218)
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
}

void games::mooGame::addControl(std::string newFilename, int action) {
	//DEBUG(games::mooGame::character.size());
	DEBUG("adding control");
	std::string ncntl = "cntl" + std::to_string(controls.size());
	sprites::Controls *ctrl = new sprites::Controls();
	int pY = 50 + 25 * controls.size();
	int iPx = 0;
	
	if (newFilename == "img\\ctrl_right") {
		iPx = 15;
	}
	if (newFilename == "img\\ctrl_left") {
		iPx = 92;
	}
	if (newFilename == "img\\ctrl_up") {
		iPx = 170;
	}
	if (newFilename == "img\\ctrl_down") {
		iPx = 250;
	}
	if (newFilename == "img\\ctrl_pick_drop") {
		iPx = 330;
	}

	ctrl->init(this, newFilename, 1, 0, 0, 0, 0, iPx, 415, 0, action);
	ctrl->setup();
	add(ncntl, ctrl);
	ctrl->move(25, 400, pY);
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
	int temp = pControls.size();
	maps::Map selectedLevel = tokens[curLevel - 1];

	//Replace following line with the one after it, after maps is initilaized
	//games::GameSetup::setScore(controls.size() - maps.getBScore());
	std::cout << "Best Score: " << selectedLevel.getBScore() << std::endl << "Current # controls: " << controls.size() << std::endl;
	int score = controls.size() - selectedLevel.getBScore();
	//games::GameSetup::setSc ore(controls.size() - tokens[curLevel].getBScore());
	if (pControls.size() != 0)
		while (temp > 0) {
			pControls.erase(pControls.begin());
			games::Game::remove("pCntl" + std::to_string(u));
			u++;
		}
	std::unordered_map<std::string, squares::Square *>::iterator it = selectedLevel.squareMap.begin();

	while (controls.size() > 0) {
		while (it->second->getX() != moo->getPx() || it->second->getY() != moo->getPy()) it++;
		DEBUG(controls[0]->getAction());
		switch (controls[0]->getAction()) {
		case 1:
			character[0]->moveCharacter( character[0]->getPx() - 50, character[0]->getPy(), character[0], no);
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
			addPControl("img\\ctrl_pick_drop", 5);
			no++;
			if (it->second->getGoal() == true) {
				//DEBUG("playing gMeow");
				Mix_PlayChannel(-1, gMeow, 0);
				games::Game::remove("mouse0");
				temp = pControls.size() + 0;
				if (pControls.size() != 0)
					for (int z = 0; z < temp; z++) {
						pControls.erase(pControls.begin());
						games::Game::remove("pCntl" + std::to_string(z));
					}
				curLevel++;
				if (curLevel != 3)
					addToGame(curLevel);
				else
					setDone(true);
			}
			break;
		default:
			break;
		}
		//if (no != 0) {
			std::cout << "" << std::endl;
			controls.erase(controls.begin());
			//elements.erase("cntl" + no);
			games::Game::remove("cntl" + std::to_string((no - 1)));
			//no--;
			it = selectedLevel.squareMap.begin();
		//}
	}
	if (levelComplete)
		games::GameSetup::setScore(score);
	std::cout << "controls: " << controls.size() << std::endl;
}




void games::mooGame::map() // Nick
{
	std::ifstream is("Map.txt");
	std::string line;
	std::string tmp;
	//std::unordered_map<std::string,int>;
	while (std::getline( is, line))
	{
		if (line[0] != '#'){
			maps::Map mapLevel;

			std::stringstream iss(line);
			//iss >> tmp;
			std::vector<std::string> x = moosplit(line, ',');
			mapLevel.build(stoi(x[0]), stoi(x[1]), x[2]);
			tokens.push_back(mapLevel);
			std::cout << line << std::endl;
			//std::string token;// shouldent need token.
		}

	}
	

	//std::cout << line; //Checking data
	

}

void games::mooGame::addToGame(int level)
{
	maps::Map selectedLevel = tokens[level - 1];
	
	std::unordered_map<std::string, squares::Square *>::iterator it = selectedLevel.squareMap.begin();

	while (it != selectedLevel.squareMap.end())
	{
		DEBUG(it->first);
		sprites::Sprites *square = new sprites::Sprites();
		square->init(this, "img\\box", 1, 0, 0, 0, 0, it->second->getX(), it->second->getY(), 0);
		square->setup();
		add(it->first, square);

		if (it == selectedLevel.squareMap.begin()) {
			//sprites::Sprites *moo = new sprites::Sprites();
			moo->init(this, "img\\moo", 4, 0, 0, 0, 0, it->second->getX(), it->second->getY(), 0);
			moo->setup();
			add("moo0", moo);
			character.push_back(moo);
		}
		if (it->second->getGoal() == true) {
			sprites::Sprites *mouse = new sprites::Sprites();
			mouse->init(this, "img\\mouse", 4, 0, 0, 0, 0, it->second->getX(), it->second->getY(), 0);
			mouse->setup();
			add("mouse0", mouse);
		}
		it++;
	}
}


void games::mooGame::cleanup() {

}

void games::mooGame::setupGame() {
	sprites::Sprites *back = new sprites::Sprites();
	back->init(this, "img\\back", 1);
	back->setup();
	add("back0",back);
	games::Game::remove("splash0");
	splashScreen = false;
	Mix_HaltMusic();
	addToGame(1);
	curLevel = 1;
}

void games::mooGame::levelSelection() {
	sprites::Sprites *back = new sprites::Sprites();
	back->init(this, "img\\back", 1);
	back->setup();
	add("back0", back);

	splashScreen = false;
	games::Game::remove("splash0");

}

void games::mooGame::displayCredits(){
	games::Game::remove("splash0");

	sprites::Sprites *credits = new sprites::Sprites();
	credits->init(this, "img\\credits", 1);
	credits->setup();
	add("credits0", credits);
	creditScreen = true;

	splashScreen = false;
}

void games::mooGame::displaySplash() {
	splashScreen = true;
	creditScreen = false;
	sprites::Sprites *splash = new sprites::Sprites();
	splash->init(this, "img\\splash", 1);
	splash->setup();
	add("splash0", splash);

}