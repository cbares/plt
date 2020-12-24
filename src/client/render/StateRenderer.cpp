#include "StateRenderer.h"

using namespace render;
using namespace std;

StateRenderer::StateRenderer(){
    this->create(sf::VideoMode(1000, 1000), "Rendering");
    this->setFramerateLimit(60);
}

void StateRenderer::update(std::shared_ptr<state::State> state){
    this->clear();

    shared_ptr<state::Player> player1 = state->players[0];
    shared_ptr<PlayerRenderer> playerRenderer1 = make_shared<PlayerRenderer>(player1,sf::Vector2f(0,0));
    shared_ptr<state::Player> player2 = state->players[1];
    shared_ptr<PlayerRenderer> playerRenderer2 = make_shared<PlayerRenderer>(player2,sf::Vector2f(0,501));
    this->draw(*playerRenderer1);
    this->draw(*playerRenderer2);

    for(int i =0;i<3;i++){
        shared_ptr<state::River> river = state->rivers[i];
        shared_ptr<RiverRenderer> riverRenderer = make_shared<RiverRenderer>(river,sf::Vector2f(460+180*i,50));
        this->draw(*riverRenderer);
    }
    this->display();
}