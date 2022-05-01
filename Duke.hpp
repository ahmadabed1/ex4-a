#pragma once
#include "Player.hpp"

namespace coup{
	class Duke: public Player{
	private:
		static const int TAX_AMOUNT;
	public:
		Duke(Game& game, std::string name);
		virtual ~Duke();

		void block(Player& player);
		void tax();
		virtual std::string role() const;
	};
}