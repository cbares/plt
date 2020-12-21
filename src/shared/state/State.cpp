#include "State.h"

using namespace state;
using namespace std;

Json::Value State::serialize(){
	Json::Value value;

	value["remainingTurns"] = this->remainingTurns;

	value["players"].resize(this->players.size());
	for (size_t i(0); i<this->players.size(); i++) {
		value["players"][(Json::ArrayIndex) i] = this->players.at(i)->serialize();
	}

	value["rivers"].resize(this->rivers.size());
	for (size_t i(0); i<this->rivers.size(); i++) {
		value["rivers"][(Json::ArrayIndex) i] = this->rivers.at(i)->serialize();
	}

	return value;
}

void State::unserialize(Json::Value value){
	this->ressources = value["ressources"].asInt();

	this->players.clear();
	for (Json::ArrayIndex i(0); i<value["players"].size(); i++) {
		this->players.push_back(make_shared<Player>(value["players"][i]));
	}

	this->rivers.clear();
	for (Json::ArrayIndex i(0); i<value["rivers"].size(); i++) {
		this->rivers.push_back(make_shared<River>(value["rivers"][i]));
	}
}

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
