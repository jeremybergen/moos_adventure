#pragma once
#include <vector>

#include "gameSetup.h"
#include "sprites.h"

namespace games {
	class Game: public GameSetup {
	private: std::vector<sprites::Sprites *> sprites;
	public: void add(sprites::Sprites *s);
	public: void loop(float dt);
	};
}