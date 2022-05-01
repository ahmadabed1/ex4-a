#include "Player.hpp"
using namespace coup;
const int Player::COUP_PRICE = 7;
 
Player::Player(Game& game, std::string name){}
Player::~Player(){}
void Player::income(){}
void Player::foreign_aid(){}
void Player::coup(Player& player){}

int Player::coins() const{
	return 0;
}
std::string Player::getName() const{
	return "";
}