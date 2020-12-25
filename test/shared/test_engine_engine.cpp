#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"
#include "../../src/shared/engine.h"

using namespace state;
using namespace engine;
using namespace std;

BOOST_AUTO_TEST_SUITE(test_Engine);

BOOST_AUTO_TEST_CASE(Engine_constructor){
    vector<shared_ptr<Actor>> actors;
    shared_ptr<State> state = make_shared<State>(42,"../../../res/cardsData/");
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);
    BOOST_TEST(1);

}

BOOST_AUTO_TEST_SUITE_END();