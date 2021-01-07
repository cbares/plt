#include "Human.h"
#include <iostream>

using namespace std;
using namespace engine;

Human::Human (std::shared_ptr<state::Player> player) : engine::Actor(player){
}

void Human::updateState (std::shared_ptr<state::State> state){
	// Empty commandBuffer (out of date)
	// this->commandBuffer = make_shared<engine::PickCommand>(-1,-1,player->name);
}

std::shared_ptr<engine::Command> Human::getCommand (){
    //return this->commandBuffer;
	//shared_ptr<engine::Command> command = make_shared<engine::PickCommand>(0,0,player->name);
	//this->commandBuffer = command;
	return this->commandBuffer;
}

