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

BOOST_AUTO_TEST_SUITE(test_AI);

BOOST_AUTO_TEST_CASE(AI_validCommandsInit){
    vector<shared_ptr<Actor>> actors;
    shared_ptr<State> state = make_shared<State>(42,"../../../res/cardsData/");
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);
    shared_ptr<RandomAI> randomAI = make_shared<RandomAI>(state->players[0]);
    randomAI->updateState(state);
    randomAI->validCommandsInit();
    BOOST_TEST(randomAI->validCommands.size()==5);
    
}

BOOST_AUTO_TEST_SUITE_END();