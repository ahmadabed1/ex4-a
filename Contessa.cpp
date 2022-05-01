#include "Contessa.hpp"
using namespace coup; 

Contessa::Contessa(Game& game, std::string name): Player(game, name){
	
}
Contessa::~Contessa(){
	
}

void Contessa::block(Player& player){
}
std::string Contessa::role() const{
	return "";
}