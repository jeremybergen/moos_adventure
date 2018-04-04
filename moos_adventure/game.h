#pragma once
#include <vector>

#include "gameSetup.h"
#include "sprites.h"

namespace games {
	class Game: public GameSetup {
	private: std::vector<sprites::Sprites *> sprites;
	private: std::vector<sprites::Sprites *> controls;
	public: void add(sprites::Sprites *s);
	public: void addCtrl(sprites::Sprites *s);
	public: void removeCtrl();
	public: void loop(float dt);
	};
}