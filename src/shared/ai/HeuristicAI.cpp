#include "HeuristicAI.h"
#include <iostream>

using namespace ai;
using namespace std;

std::shared_ptr<engine::Command> HeuristicAI::getCommand (){

    std::vector<std::shared_ptr<engine::Command>> validCommands = AI::validCommands(this->state,this->player);
    uint highestRiverAvailable =0;
    for(uint i =0 ;i<validCommands.size();i++){
        if(shared_ptr<engine::PickCommand> pickCommand = dynamic_pointer_cast<engine::PickCommand>(validCommands[i])){
            if(pickCommand->riverPosition > highestRiverAvailable){
                highestRiverAvailable = pickCommand->riverPosition;
            }
        }
    }
    vector<shared_ptr<engine::Command>> bestCommands;
    for(uint i =0 ;i<validCommands.size();i++){
        if(shared_ptr<engine::PickCommand> pickCommand = dynamic_pointer_cast<engine::PickCommand>(validCommands[i])){
            if(pickCommand->riverPosition == highestRiverAvailable){
                bestCommands.push_back(validCommands[i]);
            }
        }
    }
    shared_ptr<engine::Command> command = bestCommands[rand()%bestCommands.size()];
    return command;
}

HeuristicAI::HeuristicAI (std::shared_ptr<state::Player> player) : AI(player){
    
}