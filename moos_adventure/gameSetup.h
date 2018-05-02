#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#undef main

namespace games {
	class GameSetup {
	private: int maxX;
	private: int maxY;
	private: SDL_Window *window;
	private: SDL_Color White;
	private: SDL_Surface * surfaceMessage;
	private: SDL_Texture * Message;
	private: SDL_Rect Message_rect;
	private: TTF_Font * Sans;
	private: SDL_Renderer *renderer;
	private: TTF_Font * gFont;
	private: int mWidth;
	private: int mHeight;
	private: bool done;
	private: bool dead;

	public: int getMaxX();
	public: int getMaxY();
	public: void setDone(bool value);
	public: SDL_Renderer *getRenderer();
	public: SDL_Window *getWindow();
	public: void init(std::string WindowName = "Game", int newMaxX = 640, int newMaxY = 480);
	public: virtual void setup() = 0;
	public: virtual void loop(float dt) = 0;
	//public: virtual void cleanup() = 0;
	public: virtual void eventHandler(SDL_Event) = 0;
	public: void run();
	public: void exit();
	};
	
	
}