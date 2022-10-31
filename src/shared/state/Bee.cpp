//
// Created by ensea on 31/10/22.
//
#include "Bee.hpp"

state::Bee::Bee(std::string name, std::string color, std::vector<int> coord, int level) : Insect(name, color, coord,level) {
    Insect(this->Name = name, this->Color = color, this->Coord = coord, this->Level= level );
}

