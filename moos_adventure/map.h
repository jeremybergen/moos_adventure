#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "squares.h"

namespace maps {
	class Map {
	private: int _mapNum;
	private: int _bestScore;
	private: std::string _squareLayout;
	//private: std::vector<squares::Square *> _squares;
	//public: std::unordered_map<std::string, squares::Square* > squareMap;
	public: std::vector<std::pair<std::string, squares::Square*>> squareMap;



	public: void build(int mapNum, int bestScore, std::string layout);
	public: int getBScore();
	};
}