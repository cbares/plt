#include "CommandMessage.h"

using namespace network;
using namespace std;

CommandMessage::CommandMessage (Json::Value value){
    this->id = MessageID::COMMAND;
    this->command = std::make_shared<engine::PickCommand>(value["command"]);
}
CommandMessage::CommandMessage (std::shared_ptr<engine::Command> command){
    this->id = MessageID::COMMAND;
}
Json::Value CommandMessage::serialize (){
    Json::Value value = this->Message::serialize();
    value["command"] = command->serialize();
    return value;
}
