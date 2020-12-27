#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"
#include "../../src/shared/engine.h"
#include "../../src/shared/ai.h"

using namespace state;
using namespace engine;
using namespace std;
using namespace ai;

BOOST_AUTO_TEST_SUITE(test_Engine);

BOOST_AUTO_TEST_CASE(Engine_replay){
    srand(time(NULL));
    shared_ptr<State> state = make_shared<State>(200,"../../../res/cardsData/",rand());
    std::vector<std::shared_ptr<Actor>> actors;
    actors.push_back(make_shared<RandomAI>(state->players[0]));
    actors.push_back(make_shared<RandomAI>(state->players[1]));
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);
    while(state->winnerIndex == -1){
        engine->step();
    }
    engine->step();

    engine->saveReplay("replay.json");

    std::vector<std::shared_ptr<Actor>> replayActors;
    shared_ptr<Engine> replayEngine = make_shared<Engine>(replayActors,nullptr);
    
    BOOST_TEST(replayEngine->loadReplay("wrongreplay.json","../../../res/cardsData/") == -1);

    BOOST_TEST(replayEngine->loadReplay("replay.json","../../../res/cardsData/") == 0);
    shared_ptr<State> replayState = replayEngine->state;
    while(replayState->winnerIndex == -1){
        replayEngine->step();
    }
    replayEngine->step();



}

BOOST_AUTO_TEST_SUITE_END();