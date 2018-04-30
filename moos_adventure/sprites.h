#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "gameSetup.h"
//#include "game.h"
#include "animationFrame.h"
//#include "mooGame.h"

namespace sprites {
	class Sprites {
	protected: games::GameSetup *g;
	//protected: games::mooGame *character;
	protected: std::string filename;
	protected: int w, h;
	protected: float aX, aY, vX, vY, pX, pY, t0;
	protected: bool done;
	protected: std::vector<animation::animationFrame> frames;
	protected: int totalAnimationTime, totalGameTime;
	protected: int count;

	public: void add(animation::animationFrame af);
	public: virtual void loop(float dt);
	public: virtual void moveCharacter(float newPX, float newPY, sprites::Sprites *character, int size);
	public: virtual void update();
	public: virtual void updateRender();
	public: virtual void cleanup();
	public: float getPx();
	public: float getPy();
	public: void setPx(int val);
	public: void setPy(int val);
	public: void setVx(int val);
	public: void setVy(int val);
	public: virtual void move(int x, int y, int yPos);
	public: bool isDone();
	public: void init(games::GameSetup *newG, std::string newFilename, int newCount = 1, float newAX=0.0, float newAY=0.0, float newVX=0.0, float newVY=0.0, float newPX=0.0, float newPY=0.0, int newT0=0);
	public: virtual void setup();
	public: void render();
	public: void exit();
	};
}