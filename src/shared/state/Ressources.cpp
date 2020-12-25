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

Ressources::Ressources(Json::Value value){
    this->unserialize(value);
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
bool Ressources::isGreaterOrEqual(std::shared_ptr<Ressources> ressources){
    if( (this->stone >= ressources->stone) &&
        (this->stoneIncome >= ressources->stoneIncome) &&
        (this->water >= ressources->water) &&
        (this->waterIncome >= ressources->waterIncome) &&
        (this->wood >= ressources->wood) &&
        (this->woodIncome >= ressources->woodIncome) &&
        (this->victoryPoint >= ressources->victoryPoint) &&
        (this->victoryPointIncome >= ressources->victoryPointIncome)){
            return true;
        }
    else{
        return false;
    }
}

void Ressources::unserialize (Json::Value value){
    this->stone = value["stone"].asInt();
    this->stoneIncome = value["stoneIncome"].asInt();
    this->water = value["water"].asInt();
    this->waterIncome = value["waterIncome"].asInt();
    this->wood = value["wood"].asInt();
    this->woodIncome = value["woodIncome"].asInt();
    this->victoryPoint = value["victoryPoint"].asInt();
    this->victoryPointIncome = value["victoryPointIncome"].asInt();
}

Json::Value Ressources::serialize (){
    Json::Value value;

    value["stone"] = this->stone;
    value["stoneIncome"] = this->stoneIncome;
    value["water"] = this->water;
    value["waterIncome"] = this->waterIncome;
    value["wood"] = this->wood;
    value["woodIncome"] = this->woodIncome;
    value["victoryPoint"] = this->victoryPoint;
    value["victoryPointIncome"] = this->victoryPointIncome;

    return value;
}

