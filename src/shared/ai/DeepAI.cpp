#include "DeepAI.h"
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace ai;
using namespace std;
//validCommands
std::shared_ptr<engine::Command> DeepAI::getCommand (){

    std::vector<std::shared_ptr<engine::Command>> validCommands = AI::validCommands(this->state,this->player);
    
    shared_ptr<engine::Command> command;
    int bestScore = 0;
    int playerIndex;
    for(uint i=0; i<state->players.size();i++){
        if(state->players[i] == player){
            playerIndex = i;
            break;
        }
    }

    for(uint i=0; i<validCommands.size();i++){
        shared_ptr<state::State> testingState = make_shared<state::State>(state); //deep copy
        
        validCommands[i]->execute(testingState);
        testingState->players[playerIndex]->earnIncome();

        shared_ptr<state::Ressources> ressources = testingState->players[playerIndex]->ressources;
        int stoneIncomeScore = 25*max(ressources->stoneIncome,2);
        int woodIncomeScore  = 25*max(ressources->woodIncome,2);
        int waterIncomeScore = 25*max(ressources->waterIncome,2);
        int score;
        if((stoneIncomeScore+woodIncomeScore+waterIncomeScore)<75){
            int stoneScore = max(ressources->stoneIncome,10);
            int woodScore  = max(ressources->woodIncome,10);
            int waterScore = max(ressources->waterIncome,10);
            score = waterScore + woodScore + stoneScore + waterIncomeScore + woodIncomeScore + stoneIncomeScore;
        }
        else{
            int victoryPointScore = (ressources->victoryPointIncome*testingState->remainingTurns + ressources->victoryPoint);
            score = victoryPointScore + waterIncomeScore + woodIncomeScore +stoneIncomeScore;
        }

        if(score>=bestScore){
            command = validCommands[i];
            bestScore = score;
        }
    }
    
    return command;
}

DeepAI::DeepAI (std::shared_ptr<state::Player> player) : AI(player){
    
}

/*
function alphabeta(node, depth, α, β, maximizingPlayer) is
    if depth = 0 or node is a terminal node then
        return the heuristic value of node
    if maximizingPlayer then
        value := −∞
        for each child of node do
            value := max(value, alphabeta(child, depth − 1, α, β, FALSE))
            α := max(α, value)
            if α ≥ β then
                break (* β cutoff *)
        return value
    else
        value := +∞
        for each child of node do
            value := min(value, alphabeta(child, depth − 1, α, β, TRUE))
            β := min(β, value)
            if β ≤ α then
                break (* α cutoff *)
        return value
*/

int DeepAI::alphabeta (std::shared_ptr<Node> node, bool max, int alpha, int beta, int depth){
    if((depth == 0 )||(node->terminalNode = true)){
        return node->heuristicValue();
    }
    if(max){
        int value = INT32_MIN;
        for(auto it = node->childs.begin();it != node->childs.end();it++){
            std::shared_ptr<Node> child = *it;
            value = std::max<int>(value,alphabeta(child,false,alpha,beta,depth-1));
            alpha = std::max(alpha,value);
            if(alpha >= beta){
                break;
            }
        }
        return value;
    }
    else{
        int value = INT32_MAX;
        for(auto it = node->childs.begin();it != node->childs.end();it++){
            std::shared_ptr<Node> child = *it;
            value = std::max<int>(value,alphabeta(child,true,alpha,beta,depth-1));
            beta = std::max(beta,value);
            if(beta <= alpha){
                break;
            }
        }
        return value;
    }
}
