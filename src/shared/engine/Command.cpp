#include "Command.h"

using namespace engine;
using namespace std;

CommandID Command::getId() const{
    return this->id;
}

void Command::setId(CommandID id){
    this->id = id;
}

const std::string& Command::getPlayerName() const{
    return playerName;
}

void Command::setPlayerName(const std::string& playerName){
    this->playerName = playerName;
}