
#include "Engine.hpp"

engine::Engine::Engine(state::Game& game) {
    this->currentState=game;
}


state::Game engine::Engine::getState() {
    return this->currentState;
}

void engine::Engine::addCommand(Command ptr_cmd) {
    this->listCommands.push_back(ptr_cmd);
}

void engine::Engine::setState(state::Game& game) {
    this->currentState=game;

}
