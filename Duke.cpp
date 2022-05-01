#include "Duke.hpp"
using namespace coup;
const int Duke::TAX_AMOUNT = 3;
 
Duke::Duke(Game& game, std::string name): Player(game, name){
	
}
Duke::~Duke(){
	
}

void Duke::block(Player& player){
	
}
void Duke::tax(){}
std::string Duke::role() const{
	return "";
}