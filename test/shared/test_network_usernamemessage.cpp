#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/network.h"

using namespace network;
using namespace std;


BOOST_AUTO_TEST_SUITE(network_UserNameMessage)


BOOST_AUTO_TEST_CASE(UserNameMessage_constructor){

    std::string userName = "test";
    std::shared_ptr<Message> message = std::make_shared<UserNameMessage>(userName);

    std::shared_ptr<UserNameMessage> userNameMessage = std::dynamic_pointer_cast<UserNameMessage>(message);

    BOOST_TEST((message->getId() == MessageID::USERNAME));

    BOOST_TEST(userNameMessage);
    BOOST_TEST((userNameMessage->getId() == MessageID::USERNAME));
	BOOST_TEST(userNameMessage->userName == "test");

}   

BOOST_AUTO_TEST_CASE(UserNameMessage_serialization_constructor){

    std::string userName = "test";
    Json::Value value;
    value["userName"]=userName;
    std::shared_ptr<Message> message = std::make_shared<UserNameMessage>(value);

    std::shared_ptr<UserNameMessage> userNameMessage = std::dynamic_pointer_cast<UserNameMessage>(message);

    BOOST_TEST((message->getId() == MessageID::USERNAME));

    BOOST_TEST(userNameMessage);
    BOOST_TEST((userNameMessage->getId() == MessageID::USERNAME));
	BOOST_TEST(userNameMessage->userName == "test");
}

BOOST_AUTO_TEST_CASE(UserNameMessage_serialization){

    std::string userName = "test";
    std::shared_ptr<UserNameMessage> userNameMessage = std::make_shared<UserNameMessage>(userName);

    Json::Value value = userNameMessage->serialize();
    BOOST_TEST((value["id"].asUInt() == (uint) MessageID::USERNAME));
    BOOST_TEST((value["userName"].asString() == "test"));
}

BOOST_AUTO_TEST_CASE(UserNameMessage_unserialization){
    
    std::string userName = "test";
    std::shared_ptr<UserNameMessage> userNameMessage1 = std::make_shared<UserNameMessage>(userName);
    Json::Value value = userNameMessage1->serialize();

    std::shared_ptr<Message> message = Message::unserialize(value);

    std::shared_ptr<UserNameMessage> userNameMessage2 = std::dynamic_pointer_cast<UserNameMessage>(message);
    BOOST_TEST(userNameMessage2);
    BOOST_TEST((userNameMessage2->getId() == MessageID::USERNAME));
	BOOST_TEST(userNameMessage2->userName == "test");
}

BOOST_AUTO_TEST_SUITE_END();