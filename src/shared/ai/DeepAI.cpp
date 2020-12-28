#include "DeepAI.h"
#include <iostream>
#include <algorithm>

using namespace ai;
using namespace std;
//validCommands
std::shared_ptr<engine::Command> DeepAI::getCommand (){
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