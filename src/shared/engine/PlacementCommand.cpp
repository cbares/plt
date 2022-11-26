//
// Created by Alith on 25/11/2022.
//
#include "PlacementCommand.hpp"
#include "iostream"

using namespace std;

engine::PlacementCommand::PlacementCommand(state::GameStatus gamestatus, std::vector<int> position_insect,
                                           state::Insect& insect, CommandTypeId commandId, state::Player& player,vector<vector<int>> placement_possible) {
    this->position=position_insect;
    this->insect=&insect;
    this->player=&player;
    this->playing=gamestatus;
    this->commandTypeId=commandId;
    this->placement_possible=placement_possible;
}

bool engine::PlacementCommand::execute(engine::Engine &engine) {

    for (auto cas_temp : this->placement_possible){
        if((this->position[0]==cas_temp[0])&&(this->position[1]==cas_temp[1])&&(this->insect->GetIsPlaced()==false)){
            engine.UpdateState(*engine.getState(), 0, *insect, this->position,*this->player);
            return 1;
        }
    }
    return 0;

    //engine.UpdateState(*engine.getState(), 0,(state::Insect&) this->insect, this->position);
}



