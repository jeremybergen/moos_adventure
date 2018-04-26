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

}