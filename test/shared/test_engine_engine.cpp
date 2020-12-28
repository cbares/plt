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

    BOOST_TEST(state->players[0]->ressources->wood == replayState->players[0]->ressources->wood);
    BOOST_TEST(state->players[0]->ressources->woodIncome == replayState->players[0]->ressources->woodIncome);
    BOOST_TEST(state->players[0]->ressources->stone == replayState->players[0]->ressources->stone);
    BOOST_TEST(state->players[0]->ressources->stoneIncome == replayState->players[0]->ressources->stoneIncome);
    BOOST_TEST(state->players[0]->ressources->water == replayState->players[0]->ressources->water);
    BOOST_TEST(state->players[0]->ressources->waterIncome == replayState->players[0]->ressources->waterIncome);
    BOOST_TEST(state->players[0]->ressources->victoryPoint == replayState->players[0]->ressources->victoryPoint);
    BOOST_TEST(state->players[0]->ressources->victoryPointIncome == replayState->players[0]->ressources->victoryPointIncome);
    BOOST_TEST(state->players[1]->ressources->wood == replayState->players[1]->ressources->wood);
    BOOST_TEST(state->players[1]->ressources->woodIncome == replayState->players[1]->ressources->woodIncome);
    BOOST_TEST(state->players[1]->ressources->stone == replayState->players[1]->ressources->stone);
    BOOST_TEST(state->players[1]->ressources->stoneIncome == replayState->players[1]->ressources->stoneIncome);
    BOOST_TEST(state->players[1]->ressources->water == replayState->players[1]->ressources->water);
    BOOST_TEST(state->players[1]->ressources->waterIncome == replayState->players[1]->ressources->waterIncome);
    BOOST_TEST(state->players[1]->ressources->victoryPoint == replayState->players[1]->ressources->victoryPoint);
    BOOST_TEST(state->players[1]->ressources->victoryPointIncome == replayState->players[1]->ressources->victoryPointIncome);
}

BOOST_AUTO_TEST_SUITE_END();