#include "Assassin.hpp"
using namespace coup;

const int Assassin::COUP_PRICE = 3;

Assassin::Assassin(Game& game, std::string name): Player(game, name){
	
}
Assassin::~Assassin(){
	
}

void Assassin::coup(Player& player){
}

std::string Assassin::role() const{
	return "";
}