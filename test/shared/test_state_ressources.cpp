#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"

using namespace state;
using namespace std;

BOOST_AUTO_TEST_SUITE(state_Ressources)

BOOST_AUTO_TEST_CASE(Ressources_constructor){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    BOOST_TEST(ressources->stone == 1);
    BOOST_TEST(ressources->stoneIncome == 2);
    BOOST_TEST(ressources->water == 3);
    BOOST_TEST(ressources->waterIncome == 4);
    BOOST_TEST(ressources->wood == 5);
    BOOST_TEST(ressources->woodIncome == 6);
    BOOST_TEST(ressources->victoryPoint == 7);
    BOOST_TEST(ressources->victoryPointIncome == 8);
}

BOOST_AUTO_TEST_CASE(Ressources_add){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Ressources> ressources_to_add = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    ressources->add(ressources_to_add);

    BOOST_TEST(ressources->stone == 2);
    BOOST_TEST(ressources->stoneIncome == 4);
    BOOST_TEST(ressources->water == 6);
    BOOST_TEST(ressources->waterIncome == 8);
    BOOST_TEST(ressources->wood == 10);
    BOOST_TEST(ressources->woodIncome == 12);
    BOOST_TEST(ressources->victoryPoint == 14);
    BOOST_TEST(ressources->victoryPointIncome == 16);
}

BOOST_AUTO_TEST_CASE(Ressources_sub){
    shared_ptr<Ressources> ressources = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    shared_ptr<Ressources> ressources_to_sub = make_shared<Ressources>(2,3,4,5,6,7,8,9);
    ressources->sub(ressources_to_sub);

    BOOST_TEST(ressources->stone == -1);
    BOOST_TEST(ressources->stoneIncome == -1);
    BOOST_TEST(ressources->water == -1);
    BOOST_TEST(ressources->waterIncome == -1);
    BOOST_TEST(ressources->wood == -1);
    BOOST_TEST(ressources->woodIncome == -1);
    BOOST_TEST(ressources->victoryPoint == -1);
    BOOST_TEST(ressources->victoryPointIncome == -1);
}

BOOST_AUTO_TEST_CASE(Ressources_greaterOrEqual){
    shared_ptr<Ressources> ressources;
    shared_ptr<Ressources> ressources_to_compare_to;

    ressources = make_shared<Ressources>(0,0,0,0,0,0,1,0);
    ressources_to_compare_to = make_shared<Ressources>(0,0,0,0,0,0,0,0);
    BOOST_TEST(ressources->isGreaterOrEqual(ressources_to_compare_to));

    ressources = make_shared<Ressources>(0,1,0,0,0,0,0,0);
    ressources_to_compare_to = make_shared<Ressources>(0,2,0,0,0,0,0,0);
    BOOST_TEST(!(ressources->isGreaterOrEqual(ressources_to_compare_to)));

    ressources = make_shared<Ressources>(0,1,0,0,0,0,0,0);
    ressources_to_compare_to = make_shared<Ressources>(0,0,0,0,0,3,0,0);
    BOOST_TEST(!(ressources->isGreaterOrEqual(ressources_to_compare_to)));
}

BOOST_AUTO_TEST_CASE(Ressources_serialization){
    shared_ptr<Ressources> ressources1 = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    Json::Value value = ressources1->serialize();
    shared_ptr<Ressources> ressources2 = make_shared<Ressources>();
    ressources2->unserialize(value);

    BOOST_TEST(ressources2->stone == 1);
    BOOST_TEST(ressources2->stoneIncome == 2);
    BOOST_TEST(ressources2->water == 3);
    BOOST_TEST(ressources2->waterIncome == 4);
    BOOST_TEST(ressources2->wood == 5);
    BOOST_TEST(ressources2->woodIncome == 6);
    BOOST_TEST(ressources2->victoryPoint == 7);
    BOOST_TEST(ressources2->victoryPointIncome == 8);
}

BOOST_AUTO_TEST_CASE(Ressources_serialization_constructor){
    shared_ptr<Ressources> ressources1 = make_shared<Ressources>(1,2,3,4,5,6,7,8);
    Json::Value value = ressources1->serialize();
    shared_ptr<Ressources> ressources2 = make_shared<Ressources>(value);

    BOOST_TEST(ressources2->stone == 1);
    BOOST_TEST(ressources2->stoneIncome == 2);
    BOOST_TEST(ressources2->water == 3);
    BOOST_TEST(ressources2->waterIncome == 4);
    BOOST_TEST(ressources2->wood == 5);
    BOOST_TEST(ressources2->woodIncome == 6);
    BOOST_TEST(ressources2->victoryPoint == 7);
    BOOST_TEST(ressources2->victoryPointIncome == 8);
}

BOOST_AUTO_TEST_SUITE_END();