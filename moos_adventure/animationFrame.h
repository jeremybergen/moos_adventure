#pragma once

#include "gameSetup.h"
#include <SDL.h>

namespace animation {
	class animationFrame {
	private: SDL_Texture *texture;
	private: games::GameSetup *g;
	private: int w, h, time;
	private: bool done;

	public: int getTime();
	public: void render(games::GameSetup *g, int x, int y);
	public: void init(SDL_Surface *newSurface, SDL_Rect src, float newTime = 1);
	public: void setup(games::GameSetup *g, std::string filename, int time);
	public: void cleanup();
	};
}