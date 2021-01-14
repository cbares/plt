#include "StateMessage.h"

using namespace network;
using namespace std;

StateMessage::StateMessage (Json::Value value){
    this->id = MessageID::STATE;
    this->state = make_shared<state::State>(value["state"]);
}
StateMessage::StateMessage (std::shared_ptr<state::State> state){
    this->id = MessageID::STATE;
    this->state = state;
}
Json::Value StateMessage::serialize (){
    Json::Value value = this->Message::serialize();
    value["state"] = this->state->serialize();
    return value;
}
