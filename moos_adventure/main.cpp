/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
//#include <SDL.h>
//#include <stdio.h>
#include <iostream>

#include "mooGame.h"

#define DEBUG(s) std::cerr << s << std::endl;

int main(int argc, char **argv[]) {
	DEBUG("in main");
	games::mooGame moosAdventure;
	moosAdventure.init("Moo's Adventure", 640, 480);
	DEBUG("after init");
	moosAdventure.run();
	moosAdventure.exit();

	return 0;
}