#include <state/Exemple.h>  // Included from library shared_static
#include "Exemple.h"

namespace client {

void Exemple::setX (int x) {
    // Create an object from "shared" library
    state::Exemple y {};
    y.setA(x);

    this->x = x;
}

}

