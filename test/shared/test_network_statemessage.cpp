#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/network.h"
#include "../../src/shared/state.h"

using namespace network;
using namespace std;


BOOST_AUTO_TEST_SUITE(network_StateMessage)

BOOST_AUTO_TEST_CASE(StateMessage_constructor){

    shared_ptr<state::State> state = make_shared<state::State>(42,"../../../res/cardsData/");
    std::shared_ptr<Message> message = std::make_shared<StateMessage>(state);

    std::shared_ptr<StateMessage> stateMessage = std::dynamic_pointer_cast<StateMessage>(message);

    BOOST_TEST((message->getId() == MessageID::STATE));

    BOOST_TEST(stateMessage);
    BOOST_TEST((stateMessage->getId() == MessageID::STATE));
	BOOST_TEST(stateMessage->state->remainingTurns == 42);

}   

BOOST_AUTO_TEST_CASE(StateMessage_serialization_constructor){
    Json::Value value;
    shared_ptr<state::State> state = make_shared<state::State>(42,"../../../res/cardsData/");
    value["state"]=state->serialize();
    std::shared_ptr<Message> message = std::make_shared<StateMessage>(value);

    std::shared_ptr<StateMessage> stateMessage = std::dynamic_pointer_cast<StateMessage>(message);

    BOOST_TEST((message->getId() == MessageID::STATE));

    BOOST_TEST(stateMessage);
    BOOST_TEST((stateMessage->getId() == MessageID::STATE));
	BOOST_TEST(stateMessage->state->remainingTurns == 42);
}

BOOST_AUTO_TEST_CASE(StateMessage_serialization){

    
    shared_ptr<state::State> state = make_shared<state::State>(42,"../../../res/cardsData/");
    std::shared_ptr<StateMessage> stateMessage = std::make_shared<StateMessage>(state);

    Json::Value value = stateMessage->serialize();
    BOOST_TEST((value["id"].asUInt() == (uint) MessageID::STATE));
    BOOST_TEST((value["state"]["remainingTurns"].asInt() == state->remainingTurns));
}

BOOST_AUTO_TEST_CASE(StateMessage_unserialization){
    shared_ptr<state::State> state = make_shared<state::State>(42,"../../../res/cardsData/");
    std::shared_ptr<StateMessage> stateMessage1 = std::make_shared<StateMessage>(state);
    Json::Value value = stateMessage1->serialize();

    std::shared_ptr<Message> message = Message::unserialize(value);

    std::shared_ptr<StateMessage> stateMessage2 = std::dynamic_pointer_cast<StateMessage>(message);
    BOOST_TEST(stateMessage2);
    BOOST_TEST((stateMessage2->getId() == MessageID::STATE));
	BOOST_TEST(stateMessage2->state->remainingTurns == 42);
}

BOOST_AUTO_TEST_SUITE_END();
