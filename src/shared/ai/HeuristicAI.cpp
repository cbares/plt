#include "HeuristicAI.hpp"
#include "state.hpp"
#include "iostream"
#include "random"
#include <engine.hpp>
#include <cstdlib>

ai::HeuristicAI::HeuristicAI(state::Game &game) : AI(game) {
    this->ai=&game;
    this->player_a=true;
}

std::vector<int> ai::HeuristicAI::runAI() {





    return AI::runAI();
}
