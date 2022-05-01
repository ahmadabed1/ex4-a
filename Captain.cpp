#include "Captain.hpp"
using namespace coup;
 
Captain::Captain(Game& game, std::string name): Player(game, name){
	
}
Captain::~Captain(){
	
}
void Captain::block(Player& player){
}
void Captain::steal(Player& src){
}

std::string Captain::role() const{
	return "";
}