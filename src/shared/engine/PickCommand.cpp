#include "PickCommand.h"

using namespace engine;
using namespace std;

/*
    int riverPosition;
    int cardPosition;
    CommandID getId() const;
    const std::string& getPlayerName() const;
*/

PickCommand::PickCommand (int riverPosition, int cardPosition){
    this->riverPosition = riverPosition;
    this->cardPosition = cardPosition;
}

void PickCommand::execute (std::shared_ptr<state::State> state){
    
}

bool PickCommand::verify (std::shared_ptr<state::State> state){
    vector<shared_ptr<state::Player>> players = state->players;
    vector<shared_ptr<state::River>> rivers = state->rivers;

    for(auto it = players.begin();it != players.end();it++){
        if(((*it)->name == this->getPlayerName()) &&
            (this->riverPosition < rivers.size()) &&
            (this->cardPosition  < players.size())){
            return true;
        }
    }
    return false;
}

Json::Value PickCommand::serialize (){
    //Json::Value value;
}

void PickCommand::unserialize (Json::Value value){
    //value["riverPosition"].asUInt();
}
