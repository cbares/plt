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

BOOST_AUTO_TEST_SUITE(test_AI_HeuristicAI);

BOOST_AUTO_TEST_CASE(HeuristicAI_validCommandsInit){
    vector<shared_ptr<Actor>> actors;
    shared_ptr<State> state = make_shared<State>(42,"../../../res/cardsData/");
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);
    state->players[0]->ressources = make_shared<Ressources>(100,0,100,0,100,0,0,0);
    shared_ptr<HeuristicAI> heuristicAI = make_shared<HeuristicAI>(state->players[0]);
    heuristicAI->updateState(state);
    heuristicAI->validCommandsInit();
    shared_ptr<PickCommand> command = dynamic_pointer_cast<PickCommand>(heuristicAI->getCommand());
    
    BOOST_TEST(command->riverPosition == 2);  
    BOOST_TEST(command->verify(state));
    
}

BOOST_AUTO_TEST_SUITE_END();