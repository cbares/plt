#include "Card.h"

using namespace state;
using namespace std;


Card::Card (std::string name, std::shared_ptr<Ressources> cost, std::shared_ptr<Ressources> gain){
    this->name = name;
    this->cost = make_shared<Ressources>(cost);
    this->gain = make_shared<Ressources>(gain);
}

Card::Card (shared_ptr<Card> card){
    this->name = card->name;
    this->cost = make_shared<Ressources>(card->cost);
    this->gain = make_shared<Ressources>(card->gain);
}

Card::Card (Json::Value value){
    this->unserialize(value);
}

Json::Value Card::serialize (){
    Json::Value value;

    value["name"] = this->name;
    value["cost"] = this->cost->serialize();
    value["gain"] = this->gain->serialize();

    return value;
}

void Card::unserialize (Json::Value value){
    this->name = value["name"].asString();
    this->cost = make_shared<Ressources>(value["cost"]);
    this->gain = make_shared<Ressources>(value["gain"]);
}
