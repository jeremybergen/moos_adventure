#include <iostream>
#include "animationFrame.h"

int animation::animationFrame::getTime() {
	return time;
}

void animation::animationFrame::render(games::GameSetup *g, int x, int y) {
	SDL_Rect src, dest;
	src.x = (int)0;
	src.y = (int)0;
	src.w = w;
	src.h = h;

	dest.x = (int)x;
	dest.y = (int)y;
	dest.w = w;
	dest.h = h;
	SDL_RenderCopy(g->getRenderer(), texture, &src, &dest);
}

void animation::animationFrame::setup(games::GameSetup *newG, std::string filename, int newTime) {
	done = false;
	g = newG;
	time = newTime;
	SDL_Surface *image = SDL_LoadBMP(filename.c_str());
	if (image == NULL) {
		std::cout << "Could not load image: " << SDL_GetError() << std::endl;
		done = true;
		return;
	}
	SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 0, 255, 0));
	texture = SDL_CreateTextureFromSurface(g->getRenderer(), image);
	if (texture == NULL) {
		std::cout << "In animationFrame" << std::endl;
		std::cout << "Could not create texture: " << SDL_GetError() << std::endl;
		done = true;
		return;
	}
	SDL_FreeSurface(image);
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
}

void animation::animationFrame::cleanup() {
	SDL_DestroyTexture(texture);
}