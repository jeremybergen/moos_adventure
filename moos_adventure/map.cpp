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

void maps::Map::build(int mapNum, int bestScore, std::string layout) {
	_mapNum = mapNum;
	_bestScore = bestScore;
	_squareLayout = layout;

	//std::cout << "start of string by char:" << std::endl;
	std::vector<std::string> x = split(layout, ';');
	int idxSquare = 0;

	for (auto &square : x) {
		squares::Square *tmpSquare = new squares::Square();
		tmpSquare->init(square);
		std::string tmpString = std::to_string(tmpSquare->getX()) + ":" + std::to_string(tmpSquare->getY()) + ":" + "square" + std::to_string(idxSquare);
		//squareMap.insert({ tmpString, tmpSquare });
		squareMap.push_back(std::make_pair(tmpString, tmpSquare));
		idxSquare++;
	}
}

int maps::Map::getBScore() {
	return _bestScore;
}

