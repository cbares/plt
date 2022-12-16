#include "AI.hpp";


ai::AI::AI(state::Game &game) {
this->ai=&game;
this->player_a=true;
}

std::vector<int> ai::AI::runAI() {
    return {0};
}

