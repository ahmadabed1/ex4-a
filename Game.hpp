#pragma once
#include <vector>
#include <string>
namespace coup{
	class Player;

	class Game{
	private:
		std::vector<Player*> m_players;
		int m_turn;
		int m_round;

	public:
		std::string turn() const;
		
		void addPlayer();
		void turnFinished();

		std::vector<std::string> players() const;
		int getRound() const;

		std::string winner() const;
	};
}