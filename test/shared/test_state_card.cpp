#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"

using namespace state;
using namespace std;

BOOST_AUTO_TEST_SUITE(shared_Card)

BOOST_AUTO_TEST_CASE(Card_constructor){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Card> card = make_shared<Card>("test",ressources,ressources);
    BOOST_TEST(card->name == "test");
    BOOST_TEST(card->cost->stone == 1);
    BOOST_TEST(card->cost->stoneIncome == 2);
    BOOST_TEST(card->cost->water == 3);
    BOOST_TEST(card->cost->waterIncome == 4);
    BOOST_TEST(card->cost->wood == 5);
    BOOST_TEST(card->cost->woodIncome == 6);
    BOOST_TEST(card->cost->victoryPoint == 7);
    BOOST_TEST(card->cost->victoryPointIncome == 8);
    BOOST_TEST(card->gain->stone == 1);
    BOOST_TEST(card->gain->stoneIncome == 2);
    BOOST_TEST(card->gain->water == 3);
    BOOST_TEST(card->gain->waterIncome == 4);
    BOOST_TEST(card->gain->wood == 5);
    BOOST_TEST(card->gain->woodIncome == 6);
    BOOST_TEST(card->gain->victoryPoint == 7);
    BOOST_TEST(card->gain->victoryPointIncome == 8);
}

BOOST_AUTO_TEST_CASE(Card_serialization){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Card> card1 = make_shared<Card>("test",ressources,ressources);
    Json::Value value = card1->serialize();
    shared_ptr<Card> card2 = make_shared<Card>(value);

    BOOST_TEST(card2->name == "test");
    BOOST_TEST(card2->cost->stone == 1);
    BOOST_TEST(card2->cost->stoneIncome == 2);
    BOOST_TEST(card2->cost->water == 3);
    BOOST_TEST(card2->cost->waterIncome == 4);
    BOOST_TEST(card2->cost->wood == 5);
    BOOST_TEST(card2->cost->woodIncome == 6);
    BOOST_TEST(card2->cost->victoryPoint == 7);
    BOOST_TEST(card2->cost->victoryPointIncome == 8);
    BOOST_TEST(card2->gain->stone == 1);
    BOOST_TEST(card2->gain->stoneIncome == 2);
    BOOST_TEST(card2->gain->water == 3);
    BOOST_TEST(card2->gain->waterIncome == 4);
    BOOST_TEST(card2->gain->wood == 5);
    BOOST_TEST(card2->gain->woodIncome == 6);
    BOOST_TEST(card2->gain->victoryPoint == 7);
    BOOST_TEST(card2->gain->victoryPointIncome == 8);

}

BOOST_AUTO_TEST_SUITE_END();
