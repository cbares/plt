#include "RandomAI.h"

using namespace ai;
using namespace std;

std::shared_ptr<engine::Command> RandomAI::getCommand (){
    return validCommands[rand()%validCommands.size()];
}

RandomAI::RandomAI (std::shared_ptr<state::Player> player) : AI(player){
    
}