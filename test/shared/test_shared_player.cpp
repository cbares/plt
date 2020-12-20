#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"

using namespace state;
using namespace std;


BOOST_AUTO_TEST_SUITE(shared_Player)

BOOST_AUTO_TEST_CASE(Player_constructor){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Player> player = make_shared<Player>(ressources);
    BOOST_TEST(player->ressources->stone == 1);
    BOOST_TEST(player->ressources->stoneIncome == 2);
    BOOST_TEST(player->ressources->water == 3);
    BOOST_TEST(player->ressources->waterIncome == 4);
    BOOST_TEST(player->ressources->wood == 5);
    BOOST_TEST(player->ressources->woodIncome == 6);
    BOOST_TEST(player->ressources->victoryPoint == 7);
    BOOST_TEST(player->ressources->victoryPointIncome == 8);
}

BOOST_AUTO_TEST_CASE(Player_serialization){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Player> player1 = make_shared<Player>(ressources);
    Json::Value value = player1->serialize();
    shared_ptr<Player> player2 = make_shared<Player>(value);
    BOOST_TEST(player2->ressources->stone == 1);
    BOOST_TEST(player2->ressources->stoneIncome == 2);
    BOOST_TEST(player2->ressources->water == 3);
    BOOST_TEST(player2->ressources->waterIncome == 4);
    BOOST_TEST(player2->ressources->wood == 5);
    BOOST_TEST(player2->ressources->woodIncome == 6);
    BOOST_TEST(player2->ressources->victoryPoint == 7);
    BOOST_TEST(player2->ressources->victoryPointIncome == 8);
}

BOOST_AUTO_TEST_CASE(Player_earnIncome){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Player> player = make_shared<Player>(ressources);
    player->earnIncome();
    BOOST_TEST(player->ressources->stone == 3);
    BOOST_TEST(player->ressources->stoneIncome == 2);
    BOOST_TEST(player->ressources->water == 7);
    BOOST_TEST(player->ressources->waterIncome == 4);
    BOOST_TEST(player->ressources->wood == 11);
    BOOST_TEST(player->ressources->woodIncome == 6);
    BOOST_TEST(player->ressources->victoryPoint == 15);
    BOOST_TEST(player->ressources->victoryPointIncome == 8);
}

BOOST_AUTO_TEST_CASE(Player_pick){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Player> player = make_shared<Player>(ressources);

    shared_ptr<Ressources> cost = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Ressources> gain = make_shared<Ressources>(0,0,0,0,0,0,0,0);
    shared_ptr<Card> card = make_shared<Card>("test",cost,gain);

    player->pick(card);
    BOOST_TEST(player->ressources->stone == 0);
    BOOST_TEST(player->ressources->stoneIncome == 0);
    BOOST_TEST(player->ressources->water == 0);
    BOOST_TEST(player->ressources->waterIncome == 0);
    BOOST_TEST(player->ressources->wood == 0);
    BOOST_TEST(player->ressources->woodIncome == 0);
    BOOST_TEST(player->ressources->victoryPoint == 0);
    BOOST_TEST(player->ressources->victoryPointIncome == 0);

    player = make_shared<Player>(ressources);
    
    cost = make_shared<Ressources>(0,0,0,0,0,0,0,0);
    gain = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    card = make_shared<Card>("test",cost,gain);

    player->pick(card);
    BOOST_TEST(player->ressources->stone == 2);
    BOOST_TEST(player->ressources->stoneIncome == 4);
    BOOST_TEST(player->ressources->water == 6);
    BOOST_TEST(player->ressources->waterIncome == 8);
    BOOST_TEST(player->ressources->wood == 10);
    BOOST_TEST(player->ressources->woodIncome == 12);
    BOOST_TEST(player->ressources->victoryPoint == 14);
    BOOST_TEST(player->ressources->victoryPointIncome == 16);

}

BOOST_AUTO_TEST_SUITE_END();