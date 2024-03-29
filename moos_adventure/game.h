#pragma once
#include <vector>
#include <unordered_map>
#include "gameSetup.h"
#include "sprites.h"
#include "unordered_map"

namespace games {
	class Game: public GameSetup {
	//private: std::vector<sprites::Sprites *> sprites;
	//private: std::unordered_map<std::string, int> map; //Nick
	//public: void add(sprites::Sprites *s);

	//private: std::vector<sprites::Sprites *> sprites;
	private: std::unordered_map<std::string, sprites::Sprites *> sprites;
	//private: std::unordered_map<std::string, sprites::Sprites *> pSprites;
	//private: std::vector<sprites::Sprites *> controls;
	public: void add(std::string key, sprites::Sprites *s);
	public: void swapE(std::string key, std::string nkey);
	//public: void pAdd(std::string key, sprites::Sprites *s);
	public: void updateSprites(float dt);
	//public: void addCtrl(sprites::Sprites *s);
	public: void remove(std::string key);
	public: void clearSprites();
	//public: void removeP(std::string key);
	public: void loop(float dt);
	};
}