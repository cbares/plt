//
// Created by ali on 25/10/22.
//
#include "Case.hpp"

std::list<int> state::Case::GetPosition() {

    return this->position;
}

state::Case::Case(std::list<int> coord, bool empty) {
    this->position=coord; this->empty=empty;
}

bool state::Case::GetEmpty() {
    return this->empty;
}

void state::Case::SetEmpty(bool state) {
this->empty=state;
}

string state::Case::coordtostring() {



}

