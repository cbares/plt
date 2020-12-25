#include "Actor.h"

using namespace engine;
using namespace std;

Actor::Actor (std::shared_ptr<state::Player> player) {
    this->player = player;
}