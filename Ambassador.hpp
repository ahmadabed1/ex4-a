#pragma once
#include "Player.hpp"
namespace coup{
	class Ambassador : public Player{
	private:

	public:
		Ambassador(Game& game, std::string name);
		virtual ~Ambassador();
		void block(Player& player);
		void transfer(Player& src, Player& dst);

		virtual std::string role() const;
	};
}