#include "State.h"

using namespace state;
using namespace std;

State::State (int remainingTurns,std::string ressourcespath){
    this->remainingTurns = remainingTurns;
    
    shared_ptr<Player> player1 = make_shared<Player>();
    shared_ptr<Player> player2 = make_shared<Player>();

    players.push_back(player1);
    players.push_back(player2);

    shared_ptr<River> river1 = make_shared<River>();
    river1->load("tier1.json","../../../res/cardsData/");
    rivers.push_back(river1);

    shared_ptr<River> river2 = make_shared<River>();
    river2->load("tier1.json","../../../res/cardsData/");
    rivers.push_back(river2);

    shared_ptr<River> river3 = make_shared<River>();
    river3->load("tier1.json","../../../res/cardsData/");
    rivers.push_back(river3);

}
State::State (Json::Value value){
    this->unserialize(value);
}
Json::Value State::serialize (){
    Json::Value value;

    value["remainingTurns"] = this->remainingTurns;
    for(uint i = 0;i<rivers.size();i++){
        value["players"][i] = players[i]->serialize();
    }
    for(uint i = 0;i<rivers.size();i++){
        value["rivers"][i] = players[i]->serialize();
    }
    value["rivers"]; 
}
void State::unserialize (Json::Value value){

}