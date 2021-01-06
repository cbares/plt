#include "DeepAI.h"
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace ai;
using namespace std;
//validCommands
std::shared_ptr<engine::Command> DeepAI::getCommand (){
    std::vector<std::shared_ptr<engine::Command>> validCommands = AI::validCommands(this->state,this->player);
    
    bool maximizingPlayer;
    for(uint i=0; i<state->players.size();i++){
        if(state->players[i] == player){
            if(i == 0){
                maximizingPlayer= true;
            }
            else{
                 maximizingPlayer= false;
            }
            break;
        }
    }

    shared_ptr<Node> root = make_shared<Node>(state,4);

    int score = DeepAI::alphabeta(root,maximizingPlayer,INT32_MIN,INT32_MAX,3);

    for(auto it = root->childs.begin();it != root->childs.end();it++){
        std::shared_ptr<Node> child = *it;
        if(child->value == score){
            return child->command;
        }
    }

    cout << "error" << endl;
    return validCommands[0];

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

    if((depth == 0 )||(node->terminalNode == true)){
        return node->heuristicValue();
    }
    if(max){
        node->value = INT32_MIN;
        for(auto it = node->childs.begin();it != node->childs.end();it++){
            std::shared_ptr<Node> child = *it;
            node->value = std::max<int>(node->value,alphabeta(child,false,alpha,beta,depth-1));
            alpha = std::max(alpha,node->value);
            if(alpha >= beta){
                break;
            }
        }
        return node->value;
    }
    else{
        node->value = INT32_MAX;
        for(auto it = node->childs.begin();it != node->childs.end();it++){
            std::shared_ptr<Node> child = *it;
            node->value = std::min<int>(node->value,alphabeta(child,true,alpha,beta,depth-1));
            beta = std::min(beta,node->value);
            if(beta <= alpha){
                break;
            }
        }
        return node->value;
    }
}
