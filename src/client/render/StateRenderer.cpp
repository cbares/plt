#include "StateRenderer.h"

using namespace render;
using namespace std;

StateRenderer::StateRenderer(){
    this->window.create(sf::VideoMode(1000, 1000), "Rendering");
}

void StateRenderer::update(std::shared_ptr<state::State> state){
    this->window.clear();
    std::shared_ptr<state::State> _state = dynamic_pointer_cast<state::State>(state);
    /*shared_ptr<PlayerRenderer> playerRenderer = make_shared<PlayerRenderer>(_state->players[0]);

    this->window.draw(*playerRenderer);*/
    this->window.display(); 
}