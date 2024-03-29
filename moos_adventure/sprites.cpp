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

void sprites::Sprites::update() {
	g->loop(0);
	SDL_RenderPresent(g->getRenderer());
}

void sprites::Sprites::moveCharacter(float newPX, float newPY, Sprites *character, int no){
	int speed = 5;
	//std::string cntl = "cntl" + std::to_string(no);

	if (pX < newPX) {
		while (pX < newPX) {
			vX = speed;
			pX = pX + vX * 0.01;
			
			//elements.at("back0")->render();
			//elements.at(cntl)->render();
			g->loop(0);
			//character->render();
			
			SDL_RenderPresent(g->getRenderer());
		}
	}
	if (pX > newPX) {
		while (pX > newPX) {
			vX = speed;
			pX = pX - vX * 0.01;			
			//elements.at("back0")->render();
			//elements.at(cntl)->render();
			g->loop(0);
			//character->render();

			SDL_RenderPresent(g->getRenderer());
		}
	}
	if (pY < newPY) {
		while (pY < newPY) {
			vY = speed;
			pY = pY + vY * 0.01;
			//elements.at("back0")->render();
			//elements.at(cntl)->render();
			g->loop(0);
			//character->render();

			SDL_RenderPresent(g->getRenderer());
		}
	}
	if (pY > newPY) {
		while (pY > newPY) {
			vY = speed;
			pY = pY - vY * 0.01;
			//elements.at("back0")->render();
			//elements.at(cntl)->render();
			g->loop(0);
			//character->render();

			SDL_RenderPresent(g->getRenderer());
		}
	}
	pY = newPY;
	pX = newPX;
	vX = 0;
	vY = 0;
}

float sprites::Sprites::getPx() {
	return pX;
}

float sprites::Sprites::getPy() {
	return pY;
}

void sprites::Sprites::setPx(int val) {
	pX = val;
}

void sprites::Sprites::setPy(int val) {
	pY = val;
}

void sprites::Sprites::setVx(int val) {
	vX = val;
}

void sprites::Sprites::setVy(int val) {
	vY = val;
}

void sprites::Sprites::move(int x, int y, int yPos) {
	int speed = 5;
	vY = ((yPos - pY) / speed);
	vX = (505.0 - pX) / speed;
	while (pX < 505.0 || pY > yPos) {
		if (pX < 505)
		{
			pX = pX + vX * 0.01;
		}
		else
			vX = 0;

		if (pY > yPos)
		{
			pY = pY + vY * 0.01;
		}
		else
			vY = 0;
		g->loop(0);
		SDL_RenderPresent(g->getRenderer());
	}
	vX = 0;
	vY = 0;
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
	totalAnimationTime = 00;
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
		//DEBUG("filename is: ");
		//DEBUG(filename);
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