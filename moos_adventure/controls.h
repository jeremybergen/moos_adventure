#pragma once
#include "sprites.h"

namespace sprites {
	class Controls: public Sprites
	{
	//private: games::GameSetup *g;
	//private: std::string filename;
	//private: float aX, aY, vX, vY, pX, pY, t0;
	//private: bool done;
	//private: std::vector<animation::animationFrame> frames;
	//private: int totalAnimationTime, totalGameTime;


	public: void init(games::GameSetup *g, std::string newFilename, int newCount, float newAX = 0.0, float newAY = 0.0, float newVX = 0.0, float newVY = 0.0, float newPX = 505.0, float newPY = 50.0, int newT0 = 0);

	//public: controls();
	//public: ~controls();
	};
}
