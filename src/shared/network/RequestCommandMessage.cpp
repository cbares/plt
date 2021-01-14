#include "RequestCommandMessage.h"

using namespace network;
using namespace std;

RequestCommandMessage::RequestCommandMessage (Json::Value value){
    this->id = MessageID::REQUEST_COMMAND;
}
RequestCommandMessage::RequestCommandMessage (){
    this->id = MessageID::REQUEST_COMMAND;
}
Json::Value RequestCommandMessage::serialize (){
    Json::Value value = this->Message::serialize();
    return value;
}
