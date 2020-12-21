#include "StateRenderer.h"

using namespace render;
using namespace std;

StateRenderer::StateRenderer(){
    this->window.create(sf::VideoMode(1000, 1000), "Rendering");
}

void StateRenderer::update(std::shared_ptr<state::Observable> state){
    
}