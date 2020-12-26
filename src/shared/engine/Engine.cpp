#include "Engine.h"
#include <iostream>

using namespace engine;
using namespace std;

Engine::Engine (std::vector<std::shared_ptr<Actor>> actors, std::shared_ptr<state::State> state){
    this->state = state;
    this->actors = actors;
}

void Engine::execute (std::shared_ptr<Command> command){
    command->execute(this->state);
}

bool Engine::verify (std::shared_ptr<Command> command){
    return command->verify(this->state);
}

void Engine::step (){
    vector<shared_ptr<state::Player>> players = state->players;
    shared_ptr<state::Player> activePlayer = state->players[state->activePlayerIndex];
    if(state->winnerIndex != -1){
        return;
    }

    activePlayer->earnIncome();
            
    for(uint j =0;j<actors.size();j++){
                
        shared_ptr<Actor> actor = actors[j];
        actor->updateState(state);

        if(actor->player->name == activePlayer->name){

            shared_ptr<Command> command;
                    
            do{
                command = actor->getCommand();
            }
            while((verify(command) != true) || (command->getPlayerName() != activePlayer->name));
            execute(command);
                    
            state->endTurn();        
        }
    }   
            
    

}