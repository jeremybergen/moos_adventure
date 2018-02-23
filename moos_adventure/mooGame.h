#pragma once
#include <vector>

#include "game.h"
#include "sprites.h"

namespace games {
	class mooGame: public Game {
	private: std::vector<sprites::Sprites *> controls;
	private: std::vector<sprites::Sprites *> character;
	private: std::vector<sprites::Sprites *> goal;
	public: void setup();
	public: void eventHandler(SDL_Event e);
	public: void cleanup();
	};
}