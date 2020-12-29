#include "RandomAI.h"

using namespace ai;
using namespace std;

std::shared_ptr<engine::Command> RandomAI::getCommand (){
    std::vector<std::shared_ptr<engine::Command>> validCommands = AI::validCommands(this->state,this->player);
    return validCommands[rand()%validCommands.size()];
}

RandomAI::RandomAI (std::shared_ptr<state::Player> player) : AI(player){
    
}