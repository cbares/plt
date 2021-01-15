#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/network.h"

using namespace network;
using namespace std;

BOOST_AUTO_TEST_SUITE(network_RequestCommandMessage)

BOOST_AUTO_TEST_CASE(RequestCommandMessage_constructor){
    std::shared_ptr<Message> message = std::make_shared<RequestCommandMessage>();

    std::shared_ptr<RequestCommandMessage> requestCommandMessage = std::dynamic_pointer_cast<RequestCommandMessage>(message);

    BOOST_TEST((message->getId() == MessageID::REQUEST_COMMAND));

    BOOST_TEST(requestCommandMessage);
    BOOST_TEST((requestCommandMessage->getId() == MessageID::REQUEST_COMMAND));

}

BOOST_AUTO_TEST_CASE(RequestCommandMessage_serialization_constructor){
    Json::Value value;
    std::shared_ptr<Message> message = std::make_shared<RequestCommandMessage>(value);

    std::shared_ptr<RequestCommandMessage> requestCommandMessage = std::dynamic_pointer_cast<RequestCommandMessage>(message);

    BOOST_TEST((message->getId() == MessageID::REQUEST_COMMAND));

    BOOST_TEST(requestCommandMessage);
    BOOST_TEST((requestCommandMessage->getId() == MessageID::REQUEST_COMMAND));

}

BOOST_AUTO_TEST_CASE(RequestCommandMessage_serialization){
    std::shared_ptr<RequestCommandMessage> requestCommandMessage = std::make_shared<RequestCommandMessage>();

    Json::Value value = requestCommandMessage->serialize();
    BOOST_TEST((value["id"].asUInt() == (uint) MessageID::REQUEST_COMMAND));
}

BOOST_AUTO_TEST_CASE(RequestCommandMessage_unserialization){
    
    std::shared_ptr<RequestCommandMessage> requestCommandMessage1 = std::make_shared<RequestCommandMessage>();
    Json::Value value = requestCommandMessage1->serialize();

    std::shared_ptr<Message> message = Message::unserialize(value);

    std::shared_ptr<RequestCommandMessage> requestCommandMessage2 = std::dynamic_pointer_cast<RequestCommandMessage>(message);
    BOOST_TEST(requestCommandMessage2);
    BOOST_TEST((requestCommandMessage2->getId() == MessageID::REQUEST_COMMAND));

}

BOOST_AUTO_TEST_SUITE_END();
