#pragma once
#include <string>
#include <vector>

#include "gameSetup.h"
#include "animationFrame.h"

namespace sprites {
	class Sprites {
	protected: games::GameSetup *g;
	protected: std::string filename;
	protected: int w, h;
	protected: float aX, aY, vX, vY, pX, pY, t0;
	protected: bool done;
	protected: std::vector<animation::animationFrame> frames;
	protected: int totalAnimationTime, totalGameTime;
	protected: int count;

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