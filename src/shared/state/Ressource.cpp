#include "Ressources.h"

using namespace state;

Ressources::Ressources(int stone, int stoneIncome, int water, int waterIncome, int wood, int woodIncome, int victoryPoint, int victoryPointIncome){
    this->stone = stone;
    this->stoneIncome = stoneIncome;
    this->water = water;
    this->waterIncome = waterIncome;
    this->wood = wood;
    this->woodIncome = woodIncome;
    this->victoryPoint = victoryPoint;
    this->victoryPointIncome = victoryPointIncome;
}

void Ressources::add (std::shared_ptr<Ressources> ressources){

}
void Ressources::sub (std::shared_ptr<Ressources> ressources){

}
bool Ressources::isGreater(std::shared_ptr<Ressources> ressources){
    return false;
}

void Ressources::unserialize (Json::Value value){

}

Json::Value Ressources::serialize (){

}

