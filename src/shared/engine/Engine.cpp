#include "Engine.h"

using namespace engine;
using namespace std;

Engine::Engine (std::vector<std::shared_ptr<Actor>> actors, std::shared_ptr<state::State> state){
    this->state;
    this->actors;
}

void Engine::execute (std::shared_ptr<Command> command){
    command->execute(this->state);
}

bool Engine::verify (std::shared_ptr<Command> command){
    return command->verify(this->state);
}
