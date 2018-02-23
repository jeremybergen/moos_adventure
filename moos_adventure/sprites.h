#pragma once
#include <string>
#include <vector>

#include "gameSetup.h"
#include "animationFrame.h"

namespace sprites {
	class Sprites {
	private: games::GameSetup *g;
	private: std::string filename;
	private: int w, h, count;
	private: float aX, aY, vX, vY, pX, pY, t0;
	private: bool done;
	private: std::vector<animation::animationFrame> frames;
	private: int totalAnimationTime, totalGameTime;

	public: void add(animation::animationFrame af);
	public: virtual void loop(float dt);
	public: virtual void cleanup();
	public: bool isDone();
	public: void init(games::GameSetup *newG, std::string newFilename, int newCount = 1, float newAX=0.0, float newAY=0.0, float newVX=0.0, float newVY=0.0, float newPX=0.0, float newPY=0.0, int newT0=0);
	public: virtual void setup();
	public: void render();
	public: void exit();
	};
}