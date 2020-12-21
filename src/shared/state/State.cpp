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
    this->unserialize();
}
Json::Value State::serialize (){

}
void State::unserialize (Json::Value value){

}