#include "squares.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <vector>
//#include "mooGame.h" // added... need??

#define DEBUG(s) std::cerr << s << std::endl;

template<typename Out>
void squaresplit(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> squaresplit(const std::string &s, char delim) {
	std::vector<std::string> elems;
	squaresplit(s, delim, std::back_inserter(elems));
	return elems;
}

void squares::Square::init(std::string strsquare) {
	/* std::stringstream iss(square);
	std::string s;
	while (std::getline(iss, s, ':')) {
		std::cout << "string delimited line is: " << s;
	} */
	//int squareidx = 0;
	std::vector<std::string> x = squaresplit(strsquare, ':');
	_x = stoi(x[0]);
	_y = stoi(x[1]);

	for (int i = x[2].size() - 1; i >= 0; i--) {
		if ((x[2][i]) == '1')
		{
			switch (abs((int) (i - (x[2].size() - 1)))) {
			case 0:
				_up = true;
				break;
			case 1:
				_right = true;
				break;
			case 2:
				_down = true;
				break;
			case 3:
				_left = true;
				break;
			case 4:
				_pickup = true;
				break;
			case 5:
				_goal = true;
				break;
			case 6:
				//gold lock
				_goldLock = true;
				break;
			case 7:
				_goldKey = true;
				break;
			defaut:
				DEBUG("Not implemented yet");
				break;
			}
		}
	}
	
	//for (char& c : x[2]) {
		
		//sprites::Sprites *square = new sprites::Sprites();
		//box2->init(this, "img\\box", 1, 0, 0, 0, 0, 75.0, 150.0, 0);

		//square->init(g, "img\\box", 1, 0, 0, 0, 0, _x, _y, 0);
		//square->setup();
		
		//games::GameSetup::add(strsquare , square);
		//squareidx++;

		//SDL_Renderer* renderer = NULL;// for rendering.
		//SDL_bool done = SDL_FALSE;

		//sprites::Sprites::render(g, _x, _y); // _x: x pos and _y: y pos. use to render box0.bmp?


		/*
		if (renderer) {
		SDL_DestroyRenderer(renderer);
		}
		*/


	//	SDL_Quit();
		//return 0;
	//}
	
}

int squares::Square::getX()
{
	return _x;
}

int squares::Square::getY()
{
	return _y;
}

bool squares::Square::getUp()
{
	return _up;
}

bool squares::Square::getRight()
{
	return _right;
}

bool squares::Square::getDown()
{
	return _down;
}

bool squares::Square::getLeft()
{
	return _left;
}

bool squares::Square::getGoal()
{
	return _goal;
}

bool squares::Square::getGLock()
{
	return _goldLock;
}

bool squares::Square::getGKey()
{
	return _goldKey;
}
	/*
void Mapping(std::string)
{


}
*/