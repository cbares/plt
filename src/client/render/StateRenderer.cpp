#include "StateRenderer.h"

using namespace render;
using namespace std;

StateRenderer::StateRenderer(){
    this->create(sf::VideoMode(1000, 1000), "Rendering");

    this->texture.loadFromFile("res/textures/concrete_wall.png");
    this->font.loadFromFile("res/fonts/arial.ttf");
}

void StateRenderer::update(std::shared_ptr<state::State> state){
    this->clear();

    shared_ptr<state::Player> player1 = state->players[0];
    shared_ptr<PlayerRenderer> playerRenderer1 = make_shared<PlayerRenderer>(player1,sf::Vector2f(0,0));

    sf::Sprite stateSprite(this->texture);
    stateSprite.setScale(400/stateSprite.getLocalBounds().width,200/stateSprite.getLocalBounds().height);
    stateSprite.setPosition(0,400);
    this->draw(stateSprite);

    if(state->winnerIndex !=-1){
        sf::Text text(std::string("Winner :") + state->players[state->winnerIndex]->name ,font, 30);
        text.setPosition(10,450);

        this->draw(text);
    }
    else{
        sf::Text text(std::string("Active player :") + state->players[state->activePlayerIndex]->name ,font, 30);
        text.setPosition(10,450);

        this->draw(text);
    }
    sf::Text text(std::string("Turn remaining :") + to_string(state->remainingTurns) ,font, 30);
    text.setPosition(10,490);

    this->draw(text);

    shared_ptr<state::Player> player2 = state->players[1];
    shared_ptr<PlayerRenderer> playerRenderer2 = make_shared<PlayerRenderer>(player2,sf::Vector2f(0,600));
    this->draw(*playerRenderer1);
    this->draw(*playerRenderer2);

    for(int i =0;i<3;i++){
        shared_ptr<state::River> river = state->rivers[i];
        shared_ptr<RiverRenderer> riverRenderer = make_shared<RiverRenderer>(river,sf::Vector2f(460+180*i,50));
        this->draw(*riverRenderer);
    }
    this->display();
}