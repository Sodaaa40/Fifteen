#define CATCH_CONFIG_MAIN
#include "../thirdparty/catch.hpp"
#include "../src/game.hpp"
TEST_CASE("winCheck is computed", "[winCheck]")
{
    game fifteen;
    int res1 = fifteen.checkWin();
    int exp1 = 0;
    fifteen.shuffle();
    int res2 = fifteen.checkWin();
    int exp2 = 1;
    REQUIRE(exp1 == res1);
    REQUIRE(exp2 == res2);
}

TEST_CASE("move is computed", "[move]")
{
    game fifteen;
    int res1 = fifteen.move(12);
    int exp1 = 0;
    int res2 = fifteen.move(13);
    int exp2 = 1;
    int res3 = fifteen.move(4);
    int exp3 = 1;
    REQUIRE(exp1 == res1);
    REQUIRE(exp2 == res2);
    REQUIRE(exp3 == res3);
}


