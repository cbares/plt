#include "AckMessage.h"

using namespace network;
using namespace std;

AckMessage::AckMessage (Json::Value value){
    this->id = MessageID::ACK;
}
AckMessage::AckMessage (){
    this->id = MessageID::ACK;
}
Json::Value AckMessage::serialize (){
    Json::Value value = this->Message::serialize();
    return value;
}
