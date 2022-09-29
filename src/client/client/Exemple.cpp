#include "../client.hpp"
#include "../shared/state.hpp"

namespace client {

void Exemple::setX (int x) {
    // Create an object from "shared" library
    state::Exemple y {};
    y.setX(x);

    this->x = x;
}

}

