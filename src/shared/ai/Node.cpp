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
    this->command = command;

    command->execute(this->state);
    this->state->endTurn();

    shared_ptr<state::Player> activePlayer = state->players[state->activePlayerIndex];
    if(state->winnerIndex == -1){
        activePlayer->earnIncome();
        if(depth != 0){
            std::vector<std::shared_ptr<engine::Command>> validCommands = AI::validCommands(state,activePlayer);
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
            for(uint i =0; i<bestCommands.size();i++){
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
    std::shared_ptr<state::Player> player1 = state->players[0];
    std::shared_ptr<state::Player> player2 = state->players[1];
    return (player1->ressources->victoryPoint + player1->ressources->victoryPointIncome * state->remainingTurns) -(player2->ressources->victoryPoint + player2->ressources->victoryPointIncome * state->remainingTurns);
    //difference de point de victoires
}
