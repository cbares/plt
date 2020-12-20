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
    this->stone += ressources->stone;
    this->stoneIncome += ressources->stoneIncome;
    this->water += ressources->water;
    this->waterIncome += ressources->waterIncome;
    this->wood += ressources->wood;
    this->woodIncome += ressources->woodIncome;
    this->victoryPoint += ressources->victoryPoint;
    this->victoryPointIncome += ressources->victoryPointIncome;
}
void Ressources::sub (std::shared_ptr<Ressources> ressources){
    this->stone -= ressources->stone;
    this->stoneIncome -= ressources->stoneIncome;
    this->water -= ressources->water;
    this->waterIncome -= ressources->waterIncome;
    this->wood -= ressources->wood;
    this->woodIncome -= ressources->woodIncome;
    this->victoryPoint -= ressources->victoryPoint;
    this->victoryPointIncome -= ressources->victoryPointIncome;
}
bool Ressources::isGreater(std::shared_ptr<Ressources> ressources){
    return false;
}

void Ressources::unserialize (Json::Value value){

}

Json::Value Ressources::serialize (){

}

