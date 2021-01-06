#include "Human.h"

using namespace std;
using namespace engine;

Human::Human (std::shared_ptr<state::Player> player) : engine::Actor(player){
}

void Human::updateState (std::shared_ptr<state::State> state){
	// Empty commandBuffer (out of date)
	this->commandBuffer = nullptr;
}

std::shared_ptr<engine::Command> Human::getCommand (){
    return this->commandBuffer;
}

