#pragma once
#include <string>
#include <vector>
#include "squares.h"

namespace maps {
	class Map {
	private: int _mapNum;
	private: int _bestScore;
	private: std::vector<squares::Square *> _squares;


	public: void init(int mapNum, int bestScore, std::string layout);
	};
}