#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#undef main

namespace games {
	class GameSetup {
	private: int maxX;
	private: int pScore;
	private: int maxY;
	private: SDL_Window *window;
	protected: SDL_Color White;
	protected: SDL_Surface * surfaceMessage;
	protected: SDL_Texture * Message;
	protected: SDL_Rect Message_rect;
	protected: TTF_Font * Sans;
	protected: SDL_Renderer *renderer;
	private: TTF_Font * gFont;
	private: int mWidth;
	private: int mHeight;
	private: bool done;
	private: bool dead;
	protected: Mix_Music * gMusic = NULL;
	protected: Mix_Chunk * gMeow = NULL;
	protected: Mix_Chunk * gCry = NULL;

	public: int getMaxX();
	public: int getMaxY();
	public: void setDone(bool value);
	public: SDL_Renderer *getRenderer();
	public: SDL_Window *getWindow();
	public: void setScore(int nScore);
	public: void scoreSetup();
	public: void init(std::string WindowName = "Game", int newMaxX = 640, int newMaxY = 480);
	public: virtual void setup() = 0;
	public: virtual void loop(float dt) = 0;
	//public: virtual void cleanup() = 0;
	public: virtual void eventHandler(SDL_Event) = 0;
	public: void run();
	public: void exit();
	};
	
	
}