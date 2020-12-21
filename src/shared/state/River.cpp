#include "River.h"
#include <fstream>
#include <iostream>

using namespace state;
using namespace std;

River::River(){

}

void River::load(int tier,std::string path){
    Json::Reader reader;
    Json::Value cardPoolJson;
    std::string file;
    switch (tier)
    {
    case 1:
        file = "res/cardsData/tier1.json";
        break;
    case 2:
        file = "res/cardsData/tier2.json";
        break;
    case 3:
        file = "res/cardsData/tier3.json";
        break;
    default :
        return;
    }
    ifstream stream(file,ifstream::binary);
    reader.parse(stream,cardPoolJson,false);
    std::vector<Json::Value> cardPool;

    for(uint i =0; i<cardPoolJson["cards"].size();i++){
        Json::Value cardJson;
        std::string subFile = "res/cardsData/"+cardPoolJson["cards"][i].asString()+".json";
        ifstream subStream(subFile,ifstream::binary);
        reader.parse(subStream,cardJson,false);

        cardPool.push_back(cardJson);
    }

    this->cardPool = cardPool;
    
}

Json::Value River::serialize(){
    Json::Value river;

    Json::Value cards;
    for(uint i =0; i<cards.size();i++){
        cards[i] = this->cards[i]->serialize();
    }
    river["cards"] = cards;

    Json::Value cardPool;
    for(uint i =0; i<cardPool.size();i++){
        cardPool[i] = this->cardPool[i];
    }
    river["cardPool"] = cardPool;

    return river;
}

void River::unserialize(Json::Value value){

    std::vector<std::shared_ptr<Card>> cards;
    for(uint i =0; i<value["cards"].size();i++){
        this->cards.push_back(make_shared<Card>(value["cards"][i]));
    }
    this->cards = cards;

    std::vector<Json::Value> cardPool;
    for(uint i =0; i<value["cardPool"].size();i++){
        cardPool.push_back(value["cards"][i]);
    }
    this->cardPool = cardPool;
}

std::shared_ptr<Card> River::popCard(int position){
    std::shared_ptr<Card> card = this->cards[position];
    this->cards.erase(cards.begin()+position);
    return card;
}

void River::addCard(std::shared_ptr<Card>){

}

void River::refill(){

}
