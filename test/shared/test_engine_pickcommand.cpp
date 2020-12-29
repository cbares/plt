#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/engine.h"

using namespace engine;
using namespace std;

BOOST_AUTO_TEST_SUITE(engine_PickCommand)

BOOST_AUTO_TEST_CASE(PickCommand_constructor){
    shared_ptr<PickCommand> pickCommand = make_shared<PickCommand>(7,3,"Player 1");

    BOOST_TEST((pickCommand->getId() == CommandID::PICK));
    BOOST_TEST(pickCommand->riverPosition == 7);
    BOOST_TEST(pickCommand->cardPosition == 3);
    BOOST_TEST(pickCommand->getPlayerName() == "Player 1");

}

BOOST_AUTO_TEST_CASE(PickCommand_verify){
    shared_ptr<state::State> state = make_shared<state::State>(42,"../../../res/cardsData/");
    
    //should not work
    shared_ptr<PickCommand> wrongPickCommand1 = make_shared<PickCommand>(3,1,"Player 1");
    shared_ptr<PickCommand> wrongPickCommand2 = make_shared<PickCommand>(2,5,"Player 1");
    shared_ptr<PickCommand> wrongPickCommand3 = make_shared<PickCommand>(2,2,"Player 3");
    shared_ptr<PickCommand> wrongPickCommand4 = make_shared<PickCommand>(2,4,"Player 2");

    BOOST_TEST(wrongPickCommand1->verify(state) == false);
    BOOST_TEST(wrongPickCommand2->verify(state) == false);
    BOOST_TEST(wrongPickCommand3->verify(state) == false);
    BOOST_TEST(wrongPickCommand4->verify(state) == false);

    //should work
    shared_ptr<PickCommand> validPickCommand1 = make_shared<PickCommand>(0,0,"Player 1");
    state->players[1]->ressources = make_shared<state::Ressources>(100,100,100,0,100,0,0,0);
    shared_ptr<PickCommand> validPickCommand2 = make_shared<PickCommand>(2,4,"Player 2");
    BOOST_TEST(validPickCommand1->verify(state));
    BOOST_TEST(validPickCommand2->verify(state));
}

BOOST_AUTO_TEST_CASE(PickCommand_execute){
    shared_ptr<state::State> state = make_shared<state::State>(42,"../../../res/cardsData/");

    shared_ptr<state::Ressources> ressourcesP1BeforeTesting = make_shared<state::Ressources>(state->players[0]->ressources->serialize());
    shared_ptr<PickCommand> PickCommand1 = make_shared<PickCommand>(0,0,"Player 1");
    state->players[1]->ressources = make_shared<state::Ressources>(100,100,100,0,100,0,0,0);
    shared_ptr<state::Ressources> ressourcesP2BeforeTesting = make_shared<state::Ressources>(state->players[1]->ressources->serialize());

    shared_ptr<PickCommand> PickCommand2 = make_shared<PickCommand>(2,4,"Player 2");
    PickCommand1->execute(state);
    PickCommand2->execute(state);

    shared_ptr<state::Ressources> ressourcesP1AfterTesting = make_shared<state::Ressources>(state->players[0]->ressources->serialize());
    shared_ptr<state::Ressources> ressourcesP2AfterTesting = make_shared<state::Ressources>(state->players[1]->ressources->serialize());

    BOOST_TEST(ressourcesP1AfterTesting->isGreaterOrEqual(ressourcesP1BeforeTesting));
    BOOST_TEST(!(ressourcesP2AfterTesting->isGreaterOrEqual(ressourcesP2BeforeTesting)));

    BOOST_TEST(state->rivers[0]->cards.size() = 5);
    BOOST_TEST(state->rivers[2]->cards.size() = 5);
}

BOOST_AUTO_TEST_CASE(PickCommand_serialization){
    shared_ptr<PickCommand> pickCommand1 = make_shared<PickCommand>(7,3,"Player 1");
    Json::Value pickCommand1Json = pickCommand1->serialize();
    shared_ptr<PickCommand> pickCommand2 = make_shared<PickCommand>(0,0,"Player 2");
    pickCommand2->unserialize(pickCommand1Json);

    BOOST_TEST(pickCommand2->riverPosition == 7);
    BOOST_TEST(pickCommand2->cardPosition == 3);
    BOOST_TEST(pickCommand2->getPlayerName() == "Player 1");
}

BOOST_AUTO_TEST_CASE(PickCommand_serialization_constructor){
    shared_ptr<PickCommand> pickCommand1 = make_shared<PickCommand>(7,3,"Player 1");
    Json::Value pickCommand1Json = pickCommand1->serialize();
    shared_ptr<PickCommand> pickCommand2 = make_shared<PickCommand>(pickCommand1Json);

    BOOST_TEST(pickCommand2->riverPosition == 7);
    BOOST_TEST(pickCommand2->cardPosition == 3);
    BOOST_TEST(pickCommand2->getPlayerName() == "Player 1");
}

BOOST_AUTO_TEST_SUITE_END();
