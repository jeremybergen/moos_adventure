#pragma once
#include <string>
#include <sstream>
#include <SDL.h>
//#include "sprites.h"
//#include "mooGame.h"

namespace squares {
	class Square
		//: virtual public sprites::Sprites
	{
	private: int _x;
	private: int _y;
	private: bool _up = false;
	private: bool _right = false;
	private: bool _down = false;
	private: bool _left = false;
	private: bool _pickup = false;
	private: bool _goal = false;
	private: bool _goldLock = false;
	private: bool _goldKey = false;
	//private: std::unordered_map<std::string, squares::Square* > squareMap;

	public: void init(std::string strsquare);
	public: int getX();
	public: int getY();
	public: bool getGoal();
	public: bool getGLock();
	public: bool getGKey();
	public: bool setGLock();
	//public: std::unordered_map
	//public: Maping(std::string square);
	};
}