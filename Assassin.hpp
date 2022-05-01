#pragma once
#include "Player.hpp"
namespace coup{
	class Assassin : public Player{
	private:
		static const int COUP_PRICE;
	public:
		Assassin(Game& game, std::string name);
		virtual ~Assassin();
		
		void coup(Player& player);

		virtual std::string role() const;
	};

	
}