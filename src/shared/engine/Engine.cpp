#include "Engine.h"
#include <iostream>
#include <fstream>

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
        state->endTurn();
        this->saveReplay("replay.json");
        return;
    }

    activePlayer->earnIncome();
            
    for(uint j =0;j<actors.size();j++){
                
        shared_ptr<Actor> actor = actors[j];
        actor->updateState(state);

        if(actor->player == activePlayer){

            shared_ptr<Command> command;
                    
            do{
                command = actor->getCommand();
            }
            while((verify(command) != true) || (command->getPlayerName() != activePlayer->name));
            commandHistoric.push_back(command);
            execute(command);
            
            state->endTurn();        
        }
    }   
}

void Engine::saveReplay (std::string name){
    Json::Value replay;
    replay["seed"] = state->seed;
    
    for(uint i = 0;i<commandHistoric.size();i++){
        replay["commands"][i] = commandHistoric[i]->serialize();
    }

    Json::StyledWriter styledWriter;
    std::ofstream replay_file("replays/"+name);
    cout << to_string(replay_file.is_open()) <<endl;
    replay_file << styledWriter.write(replay);
    replay_file.close();

}

void Engine::loadReplay (std::string name){

}
