#include "State.h"

using namespace state;
using namespace std;

State::State(){
	this->remainingTurns = 10;
}

State::State(Json::Value value){
	this->unserialize(value);
}

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
