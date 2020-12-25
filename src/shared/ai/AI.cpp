#include "AI.h"

using namespace ai;
using namespace std;

AI::AI (std::shared_ptr<state::Player> player) : engine::Actor(player){
    
}

void AI::updateState (std::shared_ptr<state::State> state){
    this->state = state;
    validCommandsInit();
}

void AI::validCommandsInit (){
    this->validCommands.clear();
    vector<shared_ptr<state::River>> rivers = state->rivers;

    for(uint i_rivers = 0;i_rivers < rivers.size();i_rivers++){
        shared_ptr<state::River> river = rivers[i_rivers];
        vector<shared_ptr<state::Card>> cards = river->cards;

        for(uint i_cards = 0;i_cards < cards.size();i_cards++){
            shared_ptr<state::Card> card = cards[i_cards];
            shared_ptr<engine::Command> command = make_shared<engine::PickCommand>(i_rivers,i_cards,this->player->name);
            if(command->verify(this->state)){
                validCommands.push_back(command);    
            }
        }
    }
}
