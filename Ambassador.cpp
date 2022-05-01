#include "Ambassador.hpp"
using namespace coup;

Ambassador::Ambassador(Game& game, std::string name): Player(game, name){}
Ambassador::~Ambassador(){}
void Ambassador::block(Player& player){}
void Ambassador::transfer(Player& src, Player& dst){}

std::string Ambassador::role() const{
	return "";
}