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
    if(state->remainingTurns ==0){
        return;
    }

    for(uint i =0;i<state->players.size();i++){
        
        shared_ptr<state::Player> player = players[i];

        if(player->name == state->activePlayerName){
            
            player->earnIncome();
            
            for(uint j =0;j<actors.size();j++){
                
                shared_ptr<Actor> actor = actors[i];
                actor->updateState(state);

                if(actor->player->name == player->name){

                    shared_ptr<Command> command;
                    
                    do{
                        command = actor->getCommand();
                    }
                    while((verify(command) != true) || (command->getPlayerName() != player->name));
                    execute(command);
                    
                    state->endTurn();
                    
                    
                }
                return;
            }   
            
            cout << "can't find active player" <<endl;
        }
        
    }
    cout << "can't find active player" <<endl;
}