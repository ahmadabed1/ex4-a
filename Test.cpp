#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <string>

using namespace coup;

TEST_CASE("Taking coins")
{
	Game game{};

	Duke duke{ game, "Moshe" };
	Assassin assassin{ game, "Yossi" };

	CHECK(duke.coins() == 0);
	duke.income();
	CHECK(duke.coins() == 1);

	CHECK(assassin.coins() == 0);
	assassin.foreign_aid();
	CHECK(assassin.coins() == 2);

	CHECK(duke.coins() == 1);
	duke.tax(); // +3
	CHECK(duke.coins() == 4);

	// not dukes turn
	CHECK(game.turn().compare("Yossi") == 0);
	CHECK_THROWS(duke.income());
	// game is not over yet
	CHECK_THROWS(game.winner()); 
}

TEST_CASE("Coup small game")
{
	Game game{};

	Assassin assassin{ game, "Yossi" };
	Duke duke{ game, "Moshe" };

	assassin.foreign_aid(); // +2
	// 2 coins is not enough to coup for assassin
	duke.income(); // +1
	CHECK_THROWS(assassin.coup(duke));
	assassin.income(); // 3 coins
	// 3 coins is enough for assassin to coup
	CHECK_NOTHROW(assassin.coup(duke));
	// assassin is the only player left
	CHECK(game.players().size() == 1);
	CHECK(game.winner().compare("Yossi") == 0);
}

TEST_CASE("Force coup")
{
	Game game{};

	Assassin assassin{ game, "Yossi" };
	Duke duke{ game, "Moshe" };

	for (int i = 0; i < 5; i++){
		assassin.income(); // +1 coin
		duke.income(); // +2 coins
	}
	assassin.income(); //6 coins
	// duke must coup
	CHECK_THROWS(duke.income());
	CHECK_NOTHROW(duke.coup(assassin));

	// duke is the only player left
	CHECK(game.players().size() == 1);
}	

TEST_CASE("Blocks")
{
	Game game{};

	Duke duke{ game, "Moshe" };
	Assassin assassin{ game, "Yossi" };
	Ambassador ambassador{ game, "Meirav" };
	Captain captain{ game, "Reut" };
	Contessa contessa{ game, "Gilad" };

	duke.income(); // 1 coin
	assassin.foreign_aid(); // 2 coins
	ambassador.foreign_aid(); // 2 coin
	// cant block yourself
	CHECK_THROWS(ambassador.block(ambassador));
	// contessa cant block foreign aid
	CHECK_THROWS(contessa.block(ambassador));
	CHECK(ambassador.coins() == 2);
	// duke can block
	CHECK_NOTHROW(duke.block(ambassador));
	CHECK(ambassador.coins() == 0);
	// duke can't block the same operation twice
	CHECK_THROWS(duke.block(ambassador));
	
	captain.foreign_aid(); // 2 coins
	contessa.income(); // 1 coin
	// round 2
	duke.income(); // 2 coin
	assassin.foreign_aid(); // 4 coins
	ambassador.foreign_aid(); // 4 coin
	captain.income(); // 3 coins
	contessa.income(); // 1 coin
	// round 3
	duke.income(); // 3 coin
	// assassin's turn with enough coins to coup
	CHECK(assassin.coins() >= 3); 
	// 5 players before coup
	CHECK(game.players().size() == 5); 
	CHECK_NOTHROW(assassin.coup(duke));
	// 4 players after successfull coup
	CHECK(game.players().size() == 4); 
}
