#include "controls.h"


void sprites::Controls::init(games::GameSetup *newG, std::string newFilename, int newCount, float newAX, float newAY, float newVX, float newVY, float newPX, float newPY, int newT0) {
	g = newG;
	filename = newFilename;
	count = newCount;
	totalGameTime = newT0;
	aX = newAX;
	aY = newAY;
	vX = newVX;
	vY = newVY;
	pX = newPX;
	pY = newPY;
}
