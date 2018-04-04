#include <vector>
#include <iostream>
#include <sstream>
#include "sprites.h"
//#include "mooGame.h"
//#include "gameSetup.h"

#define DEBUG(s) std::cerr << s << std::endl;


void sprites::Sprites::add(animation::animationFrame af) {
	frames.push_back(af);
	totalAnimationTime += af.getTime();
}

void sprites::Sprites::loop(float dt) {
	//vY = 0;
	pY = pY + vY * dt;
	//vX = 0;
	pX = pX + vX * dt;
	totalGameTime += (int)(dt*1000.0);

	//vY = vY + aY * dt;
	//vX = vX + aX * dt;
}

/* void sprites::Sprites::updateSprites() {
	std::vector<sprites::Sprites *> temp;
	//temp = games::mooGame::getCharacter();
	temp = character->getCharacter();
	DEBUG("-----temp size is:");
	DEBUG(temp.size());
	DEBUG("-----end temp size");
} */

void sprites::Sprites::updateRender() {
	SDL_RenderPresent(g->getRenderer());
}

void sprites::Sprites::moveCharacter(float newPX, float newPY, Sprites *character, std::vector<sprites::Sprites *> &elements){
	int speed = 5;
	if (pX < newPX) {
		while (pX < newPX) {
			vX = speed;
			pX = pX + vX * 0.01;
			for (sprites::Sprites *temp : elements) {
				temp->render();
				character->render();

			}
			SDL_RenderPresent(g->getRenderer());
		}
	}
	if (pX > newPX) {
		while (pX > newPX) {
			vX = speed;
			pX = pX - vX * 0.01;			
			for (sprites::Sprites *temp : elements) {
				temp->render();
				character->render();

			}

			SDL_RenderPresent(g->getRenderer());
		}
	}
	if (pY < newPY) {
		while (pY < newPY) {
			vY = speed;
			pY = pY + vY * 0.01;
			for (sprites::Sprites *temp : elements) {
				temp->render();
				character->render();

			}

			SDL_RenderPresent(g->getRenderer());
		}
	}
	if (pY > newPY) {
		while (pY > newPY) {
			vY = speed;
			pY = pY - vY * 0.01;
			for (sprites::Sprites *temp : elements) {
				temp->render();
				character->render();

			}

			SDL_RenderPresent(g->getRenderer());
		}
	}

	vX = 0;
	vY = 0;
}

float sprites::Sprites::getPx() {
	return pX;
}

float sprites::Sprites::getPy() {
	return pY;
}

void sprites::Sprites::cleanup() {
	for (unsigned i = 0; i < frames.size(); i++){
		frames[i].cleanup();
	}
}

bool sprites::Sprites::isDone() {
	return done;
}

//void sprites::Sprites::init(games::GameSetup *newG, std::string newFilename, int newCount = 1, float newAX = 0.0, float newAY = 0.0, float newVX = 0.0, float newVY = 0.0, float newPX = 0.0, float newPY = 0.0, int newT0 = 0) {
void sprites::Sprites::init(games::GameSetup *newG, std::string newFilename, int newCount, float newAX, float newAY, float newVX, float newVY, float newPX, float newPY, int newT0) {
	g = newG;
	filename = newFilename;
	w = 0;
	h = 0;
	count = newCount;
	totalGameTime = newT0;
	totalAnimationTime = 0;
	aX = newAX;
	aY = newAY;
	vX = newVX;
	vY = newVY;
	pX = newPX;
	pY = newPY;
}

void sprites::Sprites::setup() {
	for (int i = 0; i < count; i++) {
		animation::animationFrame af;
		std::stringstream sstring;
		//std::cout << "filename is: " << filename << std::endl;
		DEBUG("filename is: ");
		DEBUG(filename);
		sstring << filename << i << ".bmp";
		af.setup(g, sstring.str().c_str(), 100);
		add(af);
	}
}

void sprites::Sprites::render() {
	if (frames.size() == 0) return;
	if (frames.size() == 1) {
		frames[0].render(g, pX, pY);
		return;
	}

	int withinFrame;
	withinFrame = totalGameTime%totalAnimationTime;
	int tally = 0;
	for (int i = 0; i < frames.size(); i++) {
		tally += frames[i].getTime();
		if (withinFrame < tally) {
			frames[i].render(g, pX, pY);
			break;
		}
	}
}

void sprites::Sprites::exit() {

}