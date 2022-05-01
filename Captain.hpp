#pragma once
#include "Player.hpp"
namespace coup{
	class Captain : public Player{
	private:

	public:
		Captain(Game& game, std::string name);
		virtual ~Captain();
		void block(Player& player);
		void steal(Player& src);

		virtual std::string role() const;
	};
}