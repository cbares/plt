//
// Created by Alith on 21/11/2022.
//
#include "Command.hpp"

engine::Command::Command() {

}

engine::CommandTypeId engine::Command::getCommandTypeId() {
    return this->commandTypeId;
}

void engine::Command::execute() {

}
