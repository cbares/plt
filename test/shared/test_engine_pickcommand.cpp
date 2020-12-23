#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/engine.h"

using namespace engine;
using namespace std;

BOOST_AUTO_TEST_SUITE(shared_PickCommand)

BOOST_AUTO_TEST_CASE(PickCommand_constructor){
    shared_ptr<PickCommand> pickCommand = make_shared<PickCommand>(7,3);

    BOOST_TEST(pickCommand->riverPosition == 7);
    BOOST_TEST(pickCommand->cardPosition == 3);
}

BOOST_AUTO_TEST_SUITE_END();
