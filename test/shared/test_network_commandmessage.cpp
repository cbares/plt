#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/network.h"
#include "../../src/shared/engine.h"

using namespace network;
using namespace std;


BOOST_AUTO_TEST_SUITE(network_CommandMessage)

BOOST_AUTO_TEST_CASE(CommandMessage_constructor){
    shared_ptr<engine::PickCommand> command = make_shared<engine::PickCommand>(1,1,"Player 1");
    std::shared_ptr<Message> message = std::make_shared<CommandMessage>(command);

    std::shared_ptr<CommandMessage> commandMessage = std::dynamic_pointer_cast<CommandMessage>(message);

    BOOST_TEST((message->getId() == MessageID::COMMAND));

    BOOST_TEST(commandMessage);
    BOOST_TEST((commandMessage->getId() == MessageID::COMMAND));
    BOOST_TEST((commandMessage->command->getId() == engine::CommandID::PICK));

}   

BOOST_AUTO_TEST_CASE(CommandMessage_serialization_constructor){
    Json::Value value;
    shared_ptr<engine::PickCommand> command = make_shared<engine::PickCommand>(1,1,"Player 1");
    value["command"]=command->serialize();
    std::shared_ptr<Message> message = std::make_shared<CommandMessage>(value);

    std::shared_ptr<CommandMessage> commandMessage = std::dynamic_pointer_cast<CommandMessage>(message);

    BOOST_TEST((message->getId() == MessageID::COMMAND));

    BOOST_TEST(commandMessage);
    BOOST_TEST((commandMessage->getId() == MessageID::COMMAND));
    BOOST_TEST((commandMessage->command->getId() == engine::CommandID::PICK));
}

BOOST_AUTO_TEST_CASE(CommandMessage_serialization){

    
    shared_ptr<engine::PickCommand> command = make_shared<engine::PickCommand>(1,1,"Player 1");
    std::shared_ptr<CommandMessage> commandMessage = std::make_shared<CommandMessage>(command);

    Json::Value value = commandMessage->serialize();
    BOOST_TEST((value["id"].asUInt() == (uint) MessageID::COMMAND));

    BOOST_TEST((value["command"]["id"].asUInt() == (uint) command->getId()));
}

BOOST_AUTO_TEST_CASE(CommandMessage_unserialization){

    shared_ptr<engine::PickCommand> command = make_shared<engine::PickCommand>(1,1,"Player 1");
    std::shared_ptr<CommandMessage> commandMessage1 = std::make_shared<CommandMessage>(command);
    Json::Value value = commandMessage1->serialize();

    std::shared_ptr<Message> message = Message::unserialize(value);

    std::shared_ptr<CommandMessage> commandMessage2 = std::dynamic_pointer_cast<CommandMessage>(message);
    BOOST_TEST(commandMessage2);
    BOOST_TEST((commandMessage2->getId() == MessageID::COMMAND));
    BOOST_TEST((commandMessage2->command->getId() == engine::CommandID::PICK));
}

BOOST_AUTO_TEST_SUITE_END();
