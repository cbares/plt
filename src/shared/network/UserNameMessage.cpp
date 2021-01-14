#include "UserNameMessage.h"

using namespace network;
using namespace std;

UserNameMessage::UserNameMessage (Json::Value value){
    this->id = MessageID::USERNAME;
    this->userName = value["userName"].asString();
}
UserNameMessage::UserNameMessage (std::string username){
    this->id = MessageID::USERNAME;
    this->userName = username;
}
Json::Value UserNameMessage::serialize (){
    Json::Value value = this->Message::serialize();
    value["userName"] = this->userName;
    return value;
}
