#include "squares.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <vector>

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

squares::Square::Square(std::string square) {
	/* std::stringstream iss(square);
	std::string s;
	while (std::getline(iss, s, ':')) {
		std::cout << "string delimited line is: " << s;
	} */
	std::vector<std::string> x = squaresplit(square, ':');
	_x = stoi(x[0]);
	_y = stoi(x[1]);

	for (char& c : square ) {
		if ((c) = '1')
		{
		std::cout << "True ";
		true;
		}
		else
		{
		std::cout << "false ";
		false;
		}

		
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
		
}

