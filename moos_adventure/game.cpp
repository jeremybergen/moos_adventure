#include <iostream>
#include "game.h"

#define DEBUG(s) std::cerr << s << std::endl;

void games::Game::add(std::string key, sprites::Sprites *s) {
	//DEBUG(s);

	sprites.insert({ key, s });
	//sprites.push_back(s);
}

void games::Game::swapE(std::string ocnrl, std::string ncnrl) {
	sprites.erase(ocnrl);
	sprites.insert({ ocnrl, sprites.at(ncnrl) });
}

/*void games::Game::pAdd(std::string key, sprites::Sprites *s) {
	//DEBUG(s);

	pSprites.insert({ key, s });
	//sprites.push_back(s);
}

void games::Game::addCtrl(sprites::Sprites *s) {
	controls.push_back(s);
} */

void games::Game::remove(std::string key) {
	//std::unordered_map<std::string, sprites::Sprites *>::iterator it = sprites.begin();

	// Iterate over the map using iterator
	sprites.erase(key);
	//while (it != sprites.end())
	//{
		//DEBUG(it->first);
		//it++;
	//}

	//controls.erase(controls.begin());
}
void games::Game::clearSprites()
{
	sprites.clear();
}
/*
void games::Game::removeP(std::string key) {
	std::unordered_map<std::string, sprites::Sprites *>::iterator it = pSprites.begin();

	// Iterate over the map using iterator
	pSprites.erase(key);
	while (it != pSprites.end())
	{
		DEBUG(it->first);
		it++;
	}

	//controls.erase(controls.begin());
}
*/
void games::Game::loop(float dt) {
	/*for (unsigned int i = 0; i < sprites.size(); i++) {
		sprites[i]->loop(dt);
	}
	for (unsigned int i = 0; i < sprites.size(); i++) {
		sprites[i]->render();
	} */

	/*std::unordered_map<std::string, sprites::Sprites *>::iterator it = sprites.begin();

	// Iterate over the map using iterator
	while (it != sprites.end())
	{
		//std::cout << it->first << " :: " << it->second << std::endl;
		it->second->loop(dt);
		it++;
	}
	it = sprites.begin();
	while (it != sprites.end())
	{
		//std::cout << it->first << " :: " << it->second << std::endl;
		it->second->render();
		it++;
	} */
	/*for (unsigned int i = 0; i < controls.size(); i++) {
		controls[i]->loop(dt);
	}
	for (unsigned int i = 0; i < controls.size(); i++) {
		controls[i]->render();
	}*/

	updateSprites(dt);
}

void games::Game::updateSprites(float dt) {
	std::unordered_map<std::string, sprites::Sprites *>::iterator it = sprites.begin();
	//std::unordered_map<std::string, sprites::Sprites *>::iterator pIt = pSprites.begin();
	// Iterate over the map using iterator
	while (it != sprites.end())
	{
		//std::cout << it->first << " :: " << it->second << std::endl;
		it->second->loop(dt);
		it++;
	}
	it = sprites.begin();
	while (it != sprites.end())
	{
		//std::cout << it->first << " :: " << it->second << std::endl;
		it->second->render();
		it++;
	}
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture


	/*while (pIt != pSprites.end())
	{
		//std::cout << it->first << " :: " << it->second << std::endl;

		pIt->second->loop(dt);
		pIt++;
	}
	pIt = pSprites.begin();
	while (pIt != pSprites.end())
	{
		//std::cout << it->first << " :: " << it->second << std::endl;
		pIt->second->render();
		pIt++;
	}
	*/
}