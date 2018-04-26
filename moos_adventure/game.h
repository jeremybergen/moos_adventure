#pragma once
#include <vector>

#include "gameSetup.h"
#include "sprites.h"
#include "unordered_map"

namespace games {
	class Game: public GameSetup {
	private: std::vector<sprites::Sprites *> sprites;
	//private: std::unordered_map<std::string, int> map; //Nick
	public: void add(sprites::Sprites *s);
	public: void loop(float dt);
	};
}