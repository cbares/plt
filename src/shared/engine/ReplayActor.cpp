#include "ReplayActor.h"
#include <iostream>

using namespace engine;
using namespace std;

std::shared_ptr<Command> ReplayActor::getCommand (){
    if(commands.size()>0){
        std::shared_ptr<Command> command = commands[0];
        commands.erase(commands.begin());
        return command;
    }
    else{
        return nullptr;
    }
}

void ReplayActor::updateState (std::shared_ptr<state::State> state){

}

ReplayActor::ReplayActor (std::shared_ptr<state::Player> player,std::vector<std::shared_ptr<Command>> commands) : Actor(player){
    this->commands = commands;
}