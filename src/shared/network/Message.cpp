#include "Message.h"

#include "MessageID.h"
#include "RequestCommandMessage.h"
#include "StateMessage.h"
#include "UserNameMessage.h"
#include "CommandMessage.h"
#include "AckMessage.h"

using namespace network;
using namespace std;

MessageID Message::getId() const{
    return this->id;
}

void Message::setId(MessageID id){
    this->id = id;
}

Json::Value Message::serialize (){
    Json::Value value;
    value["id"] = (uint)this->id;
    return value;
}

std::shared_ptr<Message> Message::unserialize (Json::Value value){
    MessageID id = (MessageID) value["id"].asUInt();
    std::shared_ptr<Message> message;
    switch(id){
        case MessageID::ACK :
            message = std::make_shared<AckMessage>(value);
            break;
        case MessageID::USERNAME :
            message = std::make_shared<UserNameMessage>(value);
            break;
        case MessageID::STATE :
            message = std::make_shared<StateMessage>(value);
            break;
        case MessageID::REQUEST_COMMAND :
            message = std::make_shared<RequestCommandMessage>(value);
            break;
        case MessageID::COMMAND :
            message = std::make_shared<CommandMessage>(value);
            break;
    }
    return message;
}

std::string Message::format (Json::Value value){
    std::string formattedString;
    return formattedString;
}
