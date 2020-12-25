#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"
#include "../../src/shared/engine.h"
#include "../../src/shared/ai.h"

using namespace state;
using namespace engine;
using namespace ai;
using namespace std;

BOOST_AUTO_TEST_SUITE(test_ai);

BOOST_AUTO_TEST_CASE(){
    shared_ptr<PickCommand> pickCommand = make_shared<PickCommand>(7,3,"Player 1");

    BOOST_TEST(pickCommand->riverPosition == 7);
    BOOST_TEST(pickCommand->cardPosition == 3);
    BOOST_TEST(pickCommand->getPlayerName() == "Player 1");
}

BOOST_AUTO_TEST_SUITE_END();