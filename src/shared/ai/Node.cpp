#include "Node.h"
#include <iostream>

using namespace ai;
using namespace state;
using namespace std;

//Root of the tree
Node::Node (std::shared_ptr<state::State> state, int depth){
    this->state = make_shared<State>(state);

    shared_ptr<state::Player> activePlayer = state->players[state->activePlayerIndex];
    if(state->winnerIndex == -1){
        activePlayer->earnIncome();
        if(depth != 0){
            std::vector<std::shared_ptr<engine::Command>> validCommands = AI::validCommands(state,activePlayer);
            for(uint i =0; i<validCommands.size();i++){
                std::shared_ptr<Node> child = make_shared<Node>(this->state,validCommands[i],depth-1);
                childs.push_back(child);
            }
        }

    }
    else{
        this->terminalNode = true;
        //terminal node
    }
}

Node::Node (std::shared_ptr<state::State> state, std::shared_ptr<engine::Command> command , int depth){
    this->state = make_shared<State>(state);

    command->execute(this->state);
    this->state->endTurn();

    shared_ptr<state::Player> activePlayer = state->players[state->activePlayerIndex];
    if(state->winnerIndex == -1){
        activePlayer->earnIncome();
        if(depth != 0){
            std::vector<std::shared_ptr<engine::Command>> validCommands = AI::validCommands(state,activePlayer);
            for(uint i =0; i<validCommands.size();i++){
                std::shared_ptr<Node> child = make_shared<Node>(this->state,validCommands[i],depth-1);
                childs.push_back(child);
            }
        }

    }
    else{
        this->terminalNode = true;
        //terminal node
    }
}

int Node::heuristicValue (){

}
