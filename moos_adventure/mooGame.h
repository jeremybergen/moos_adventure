#pragma once
#include <vector>
#include <unordered_map>

#include "game.h"
#include "sprites.h"
#include "controls.h"
#include "map.h"


namespace games {
	class mooGame: public Game, public maps::Map {
	private: std::vector<sprites::Controls *> controls;
	private: std::vector<sprites::Controls *> pControls;
	private: std::vector<maps::Map> tokens;


	//private: std::unordered_map<std::string, sprites::Sprites *> elements;
			 
	private: bool lComplete = true;
	private: std::vector<sprites::Sprites *> character;
	private: std::vector<sprites::Sprites *> goal;
	private: std::vector<sprites::Sprites *> elements;
	public: void setup();
	public: std::vector<sprites::Sprites *> getCharacter();
	//public: std::vector<sprites::Sprites *> getCharacter();
	public: void eventHandler(SDL_Event e);
	public: void addControl(std::string filename, int action);
	public: void addPControl(std::string filename, int action);
	public: void evalControls();
	//public: void addToGame(std::string idxname, sprites::Sprites *sprite);
	public: void addToGame(int level);
	public: void map(); // function for map?
	public: void cleanup();
	};
}