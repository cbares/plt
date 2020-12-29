#include "River.h"
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>

using namespace state;
using namespace std;

River::River(){
    this->nextCard = 0;
}

River::River(Json::Value value){
    this->unserialize(value);
}

River::River(shared_ptr<River> river){
    this->nextCard = river->nextCard;

    for(uint i =0; i<river->cards.size();i++){
        shared_ptr<Card> card = make_shared<Card>(river->cards[i]);
        this->cards.push_back(card);
    }

    for(uint i =0; i<river->cardPool.size();i++){
        this->cardPool.push_back(river->cardPool[i]);
    }
}

void River::load(std::string filename,std::string resPath){
    Json::Reader reader;
    Json::Value cardPoolJson;
    std::string filepath  = resPath + filename;

    ifstream stream(filepath,ifstream::binary);
    reader.parse(stream,cardPoolJson,false);
    std::vector<Json::Value> cardPool;

    for(uint i =0; i<cardPoolJson["cards"].size();i++){
        Json::Value cardJson;
        std::string subFilepath = resPath +cardPoolJson["cards"][i].asString()+".json";
        ifstream subStream(subFilepath,ifstream::binary);
        reader.parse(subStream,cardJson,false);

        cardPool.push_back(cardJson);
    }

    this->cardPool = cardPool;
    
}

Json::Value River::serialize(){
    Json::Value riverValue;

    riverValue["nextCard"] = nextCard;

    Json::Value cardsValue;
    for(uint i =0; i<this->cards.size();i++){
        cardsValue[i] = this->cards[i]->serialize();
    }
    riverValue["cards"] = cardsValue;

    Json::Value cardPoolValue;
    for(uint i =0; i<this->cardPool.size();i++){
        cardPoolValue[i] = this->cardPool[i];
    }
    riverValue["cardPool"] = cardPoolValue;

    return riverValue;
}

void River::unserialize(Json::Value value){

    this->nextCard = value["nextCard"].asUInt(); 

    vector<shared_ptr<Card>> cards;
    for(uint i =0; i<value["cards"].size();i++){
        shared_ptr<Card> card = make_shared<Card>(value["cards"][i]);
        cards.push_back(card);
    }
    this->cards = cards;

    vector<Json::Value> cardPool;
    for(uint i =0; i<value["cardPool"].size();i++){
        cardPool.push_back(value["cardPool"][i]);
    }
    this->cardPool = cardPool;
}

std::shared_ptr<Card> River::popCard(int position){
    shared_ptr<Card> card = this->cards[position];
    this->cards.erase(cards.begin()+position);
    return card;
}

void River::addCard(shared_ptr<Card> card){
    cards.push_back(card);
}

void River::refill(){
    while(this->cards.size()<5){
        Json::Value newCardJson = cardPool[nextCard];
        nextCard = (nextCard +1)%cardPool.size();
        shared_ptr<Card> card = make_shared<Card>(newCardJson);
        addCard(card);
    }

}
