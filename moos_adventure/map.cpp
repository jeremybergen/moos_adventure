#include <iterator>
#include <iostream>
#include "map.h"

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
		if ((c) = '1')
		{
			std::cout << "True ";
			//true;
		}
		else
		{
			std::cout << "false ";
			//false;
		}
	}
	//split(layout, ';');
	//std::cout << "this is layout, after: " << layout [0]<< layout[1] << std::endl;

}