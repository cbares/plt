#include "Human.h"

using namespace std;

Human::Human (std::shared_ptr<state::Player> player) : engine::Actor(player){
    
}

void Human::updateState (std::shared_ptr<state::State> state){
    this->state = state;
    validCommandsInit();
}

void Human::validCommandsInit (){
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

std::shared_ptr<engine::Command> Human::getCommand (){
    retrun InputManager::checkbb();
}