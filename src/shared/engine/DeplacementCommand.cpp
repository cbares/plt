//
// Created by Alith on 25/11/2022.
//
#include "DeplacementCommand.hpp"

engine::DeplacementCommand::DeplacementCommand(state::GameStatus gamestatus, std::vector<int> position_insect,
                                               state::Insect &insect, CommandTypeId commandId, state::Player &player,
                                               std::vector<std::vector<int>> placement_possible) {
    this->position=position_insect;
    this->insect=&insect;
    this->player=&player;
    this->playing=gamestatus;
    this->commandTypeId=commandId;
    this->placement_possible=placement_possible;
}

bool engine::DeplacementCommand::execute(engine::Engine &engine) {

    for (auto cas_temp : this->placement_possible){
        if((this->position[0]==cas_temp[0])&&(this->position[1]==cas_temp[1])&&(this->insect->GetIsPlaced()==true)){
            engine.UpdateState(*engine.getState(), 1, *insect, this->position,*this->player);
            return 1;
        }
    }
    return 0;



    return false;
}
