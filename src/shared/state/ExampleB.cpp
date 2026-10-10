#include "ExampleB.h"

namespace state {

    void ExampleB::setY (int y) {
        this->y=y;
        this->vy = {1, 2, 3};
    }

    ExampleB::ExampleB() = default;

    int ExampleB::getY () const {
        return y;
    }
}
