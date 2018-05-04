#pragma once
#include <string>
#include <sstream>
#include <SDL.h>

namespace squares {
	class Square {
	private: int _x;
	private: int _y;
	private: bool _up;
	private: bool _right;
	private: bool _down;
	private: bool _left;
	private: bool _pickup;

	public: Square(std::string square);
	//public: Maping(std::string square);
	};
}