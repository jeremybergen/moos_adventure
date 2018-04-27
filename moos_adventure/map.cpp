#include <iterator>
#include <iostream>
#include "map.h"
#include "SDL.h"// Testing render/draw

template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

void maps::Map::init(int mapNum, int bestScore, std::string layout) {
	_mapNum = mapNum;
	_bestScore = bestScore;

	std::vector<std::string> x = split(layout, ';');
	while (x.size() > 0) {
		std::cout << "x.size() is: " << x.size() << std::endl;
		squares::Square *squares = new squares::Square(x[0]);


		_squares.push_back(squares);
		x.erase(x.begin());

	}
	//std::cout << "start of string by char:" << std::endl;
	for (char& c : layout) {
		/*if ((c) = '1')
		{
			std::cout << "True ";
			//true;
		}
		else
		{
			std::cout << "false ";
			//false;
		}*/
	}
	//split(layout, ';');
	//std::cout << "this is layout, after: " << layout [0]<< layout[1] << std::endl; // positions data

	/*
	SDL_Renderer* renderer = NULL;
	SDL_bool done = SDL_FALSE;

	while (!done) {
		SDL_Event event;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, 25, 25, 75, 25);
		//SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
		//SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = SDL_TRUE;
			}
		}
	}

	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}

SDL_Quit();
//return 0;
*/
}

