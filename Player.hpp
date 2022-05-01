#pragma once
#include <string>
#include "Game.hpp"
namespace coup{
	class Player{
	private:
		int m_coins;
		Game* m_game;
		std::string m_name;
		int m_lastPlayedRound;

		static const int COUP_PRICE;
	public:
		Player(Game& game, std::string name);
		virtual ~Player();
		void income();
		void foreign_aid();
		void coup(Player& player);
		int coins() const;
		std::string getName() const;
		
		virtual std::string role() const=0;		
	};
}
