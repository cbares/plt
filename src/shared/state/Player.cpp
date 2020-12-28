#include "Player.h"

using namespace state;
using namespace std;

Player::Player(std::string name){
    this->name = name;
    this->ressources = make_shared<Ressources>();
}

Player::Player(shared_ptr<Player> player){
    this->name = player->name;
    this->ressources = make_shared<Ressources>(player->ressources);
}

Player::Player(Json::Value value){
    this->unserialize(value);
}


void Player::earnIncome (){
    this->ressources->stone += this->ressources->stoneIncome;
    this->ressources->wood += this->ressources->woodIncome;
    this->ressources->water += this->ressources->waterIncome;
    this->ressources->victoryPoint += this->ressources->victoryPointIncome;
}

void Player::pick(std::shared_ptr<Card> card){
    this->ressources->sub(card->cost);
    this->ressources->add(card->gain);
}

Json::Value Player::serialize(){
    Json::Value value;
    value["name"] = name;
    value["ressources"] = this->ressources->serialize();

    return value;
}

void Player::unserialize(Json::Value value){
    this->name = value["name"].asString();
    this->ressources = make_shared<Ressources>(value["ressources"]);
}
