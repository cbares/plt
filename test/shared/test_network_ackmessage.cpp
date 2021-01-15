#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/network.h"

using namespace network;
using namespace std;

BOOST_AUTO_TEST_SUITE(network_AckMessage)

BOOST_AUTO_TEST_CASE(AckMessage_constructor){
    std::shared_ptr<Message> message = std::make_shared<AckMessage>();

    std::shared_ptr<AckMessage> ackMessage = std::dynamic_pointer_cast<AckMessage>(message);

    BOOST_TEST((message->getId() == MessageID::ACK));

    BOOST_TEST(ackMessage);
    BOOST_TEST((ackMessage->getId() == MessageID::ACK));

}

BOOST_AUTO_TEST_CASE(AckMessage_serialization_constructor){
    Json::Value value;
    std::shared_ptr<Message> message = std::make_shared<AckMessage>(value);

    std::shared_ptr<AckMessage> ackMessage = std::dynamic_pointer_cast<AckMessage>(message);

    BOOST_TEST((message->getId() == MessageID::ACK));

    BOOST_TEST(ackMessage);
    BOOST_TEST((ackMessage->getId() == MessageID::ACK));

}

BOOST_AUTO_TEST_CASE(AckMessage_serialization){
    std::shared_ptr<AckMessage> ackMessage = std::make_shared<AckMessage>();

    Json::Value value = ackMessage->serialize();
    BOOST_TEST((value["id"].asUInt() == (uint) ackMessage->getId()));

}

BOOST_AUTO_TEST_CASE(AckMessage_unserialization){
    
    std::shared_ptr<AckMessage> ackMessage1 = std::make_shared<AckMessage>();
    Json::Value value = ackMessage1->serialize();

    std::shared_ptr<Message> message = Message::unserialize(value);

    std::shared_ptr<AckMessage> ackMessage2 = std::dynamic_pointer_cast<AckMessage>(message);
    BOOST_TEST(ackMessage2);
    BOOST_TEST((ackMessage2->getId() == MessageID::ACK));

}

BOOST_AUTO_TEST_SUITE_END();
