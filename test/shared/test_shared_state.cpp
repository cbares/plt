#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"

using namespace state;
using namespace std;


BOOST_AUTO_TEST_SUITE(shared_State)

BOOST_AUTO_TEST_CASE(State_constructor){
    shared_ptr<State> state = make_shared<State>(42,"../../../res/cardsData/");
	BOOST_TEST(state->remainingTurns == 42);
	BOOST_TEST(state->players.size() == 2);
	BOOST_TEST(state->rivers.size() = 3);
}

BOOST_AUTO_TEST_CASE(State_serialization){
	shared_ptr<State> state1 = make_shared<State>(42,"../../../res/cardsData/");
	shared_ptr<State> state2 = make_shared<State>(10,"../../../res/cardsData/"); // Different from state1

	Json::Value valueState1 = state1->serialize();
	state2->unserialize(valueState1);
	
	BOOST_TEST(state1->remainingTurns == state2->remainingTurns);
}

BOOST_AUTO_TEST_SUITE_END();
