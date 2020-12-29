#include "AI.h"

using namespace ai;
using namespace std;

AI::AI (std::shared_ptr<state::Player> player) : engine::Actor(player){
    
}

void AI::updateState (std::shared_ptr<state::State> state){
    this->state = state;
}

std::vector<std::shared_ptr<engine::Command>> AI::validCommands (std::shared_ptr<state::State> state, std::shared_ptr<state::Player> player){
    std::vector<std::shared_ptr<engine::Command>> validCommands;
    vector<shared_ptr<state::River>> rivers = state->rivers;

    for(uint i_rivers = 0;i_rivers < rivers.size();i_rivers++){
        shared_ptr<state::River> river = rivers[i_rivers];
        vector<shared_ptr<state::Card>> cards = river->cards;

        for(uint i_cards = 0;i_cards < cards.size();i_cards++){
            shared_ptr<state::Card> card = cards[i_cards];
            shared_ptr<engine::Command> command = make_shared<engine::PickCommand>(i_rivers,i_cards,player->name);
            if(command->verify(state)){
                validCommands.push_back(command);    
            }
        }
    }
    return validCommands;
}
