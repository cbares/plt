#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"

using namespace state;
using namespace std;


BOOST_AUTO_TEST_SUITE(state_River)

BOOST_AUTO_TEST_CASE(River_constructor){
    shared_ptr<River> river = make_shared<River>();

    BOOST_TEST(river->cardPool.empty());
    BOOST_TEST(river->cards.empty());

}

BOOST_AUTO_TEST_CASE(River_load){
    shared_ptr<River> river1 = make_shared<River>();
    river1->load("tier1.json","../../../res/cardsData/");

    BOOST_TEST(!(river1->cardPool.empty()));

    shared_ptr<River> river2 = make_shared<River>();
    river2->load("tier1.json","../../../res/cardsData/");

    BOOST_TEST(!(river2->cardPool.empty()));

    shared_ptr<River> river3 = make_shared<River>();
    river3->load("tier1.json","../../../res/cardsData/");

    BOOST_TEST(!(river3->cardPool.empty()));
}


BOOST_AUTO_TEST_CASE(River_addCard){
    shared_ptr<River> river = make_shared<River>();

    shared_ptr<Ressources> ressources = make_shared<Ressources>();
    shared_ptr<Card> card = make_shared<Card>("test",ressources,ressources);
    river->addCard(card);

    BOOST_TEST(river->cards.size() == 1);

}

BOOST_AUTO_TEST_CASE(River_refill){
    shared_ptr<River> river = make_shared<River>();
    river->load("tier1.json","../../../res/cardsData/");
    river->refill();

    BOOST_TEST(river->cards.size() == 5);
}


BOOST_AUTO_TEST_CASE(River_popCard){
    shared_ptr<River> river = make_shared<River>();
    river->load("tier1.json","../../../res/cardsData/");
    river->refill();
    river->popCard(3);

    BOOST_TEST(river->cards.size() == 4);

}

BOOST_AUTO_TEST_CASE(River_serialization){
    shared_ptr<River> river1 = make_shared<River>();
    river1->load("tier1.json","../../../res/cardsData/");
    river1->refill();

    Json::Value value = river1->serialize();
    shared_ptr<River> river2 = make_shared<River>();
    river2->unserialize(value);

    BOOST_TEST(river2->cardPool.size() == river1->cardPool.size());

    BOOST_TEST(river2->cards.size() == river1->cards.size());


}

BOOST_AUTO_TEST_CASE(River_serialization_constructor){
    shared_ptr<River> river1 = make_shared<River>();
    river1->load("tier1.json","../../../res/cardsData/");
    river1->refill();

    Json::Value value = river1->serialize();
    shared_ptr<River> river2 = make_shared<River>(value);

    BOOST_TEST(river2->cardPool.size() == river1->cardPool.size());

    BOOST_TEST(river2->cards.size() == river1->cards.size());

}

BOOST_AUTO_TEST_SUITE_END();