#pragma once
#include <string>
#include <SDL.h>

namespace games {
	class GameSetup {
	private: int maxX;
	private: int maxY;
	private: SDL_Window *window;
	private: SDL_Renderer *renderer;
	private: bool done;
	private: bool dead;

	public: int getMaxX();
	public: int getMaxY();
	public: SDL_Renderer *getRenderer();
	public: void init(std::string WindowName = "Game", int newMaxX = 640, int newMaxY = 480);
	public: virtual void setup() = 0;
	public: virtual void loop(float dt) = 0;
	public: virtual void cleanup() = 0;
	public: virtual void eventHandler(SDL_Event) = 0;
	public: void run();
	public: void exit();
	};
	
	
}