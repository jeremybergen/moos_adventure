#pragma once
#include <iostream>
#include <ctime>
#include "gameSetup.h"

int games::GameSetup::getMaxX() {
	return maxX;
}

int games::GameSetup::getMaxY() {
	return maxY;
}

void games::GameSetup::setDone(bool value) {
	done = value;
}

SDL_Window *games::GameSetup::getWindow() {
	return window;
}

SDL_Renderer *games::GameSetup::getRenderer() {
	return renderer;
}

void games::GameSetup::setScore(int nScore) {
	pScore = nScore;
	std::string sScore = "Score: " + std::to_string(pScore);
	surfaceMessage = TTF_RenderText_Solid(Sans, sScore.c_str(), White);
	Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
}

//void games::GameSetup::init(std::string WindowName = "Moo's Adventure", int newMaxX = 640, int newMaxY = 480) {
void games::GameSetup::init(std::string WindowName, int newMaxX, int newMaxY) {
	maxX = newMaxX;
	maxY = newMaxY;
	done = false;
	dead = false;
	pScore = 0;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	std::cout << "in GameSetup init()" << std::endl;
	window = SDL_CreateWindow(WindowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, maxX, maxY, SDL_WINDOW_OPENGL);
	if (window == NULL) {
		std::cout << "Could not open window: " << SDL_GetError() << std::endl;
		done = true;
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		std::cout << "Could not create render: " << SDL_GetError() << std::endl;
	}
	srand(time(NULL));



	Sans = TTF_OpenFont("img\\AGENCYR.ttf", 24); //this opens a font style and sets a size

	White = { 255, 255, 255 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
	std::string nScore = "Score: " + std::to_string(pScore);
	surfaceMessage = TTF_RenderText_Solid(Sans, nScore.c_str(), White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

	Message_rect; //create a rect
	Message_rect.x = 480;  //controls the rect's x coordinate 
	Message_rect.y = 415; // controls the rect's y coordint
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 24; // controls the height of the rect

						  //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

						  //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes
															//Don't forget too free your surface and texture

		//Get rid of old surface
		SDL_FreeSurface(surfaceMessage);
}

void games::GameSetup::run() {
	setup();
	float last = SDL_GetTicks();
	bool dead = false;
	
	while (!dead && !done) {
		SDL_Event event;
		float dt = ((float)SDL_GetTicks() - last) / 1000.0;
		last = SDL_GetTicks();
		
		loop(dt);
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)) {
			eventHandler(event);
		}
		SDL_Delay(1000 / 60);
	}
	if (!done) {
		//games::GameSetup::cleanup();
	}
}

void games::GameSetup::exit() {
	if (done) return;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}