#pragma once
#include <string>
#include <sstream>

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
	};
}