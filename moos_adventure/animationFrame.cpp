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

void animation::animationFrame::init(SDL_Surface *newSurface, SDL_Rect src, float newTime = 1) {

}

void animation::animationFrame::setup(games::GameSetup *g, std::string filename, int time) {

}

void animation::animationFrame::cleanup() {
	SDL_DestroyTexture(texture);
}