#include <iostream>

#include "mooGame.h"

#define DEBUG(s) std::cerr << s << std::endl;

int main(int argc, char **argv[]) {
	DEBUG("in main");
	games::mooGame moosAdventure;
	moosAdventure.init("Moo's Adventure", 640, 480);
	DEBUG("after init");
	moosAdventure.run();
	//moosAdventure.map();//Nick testing
	moosAdventure.exit();

	return 0;
}