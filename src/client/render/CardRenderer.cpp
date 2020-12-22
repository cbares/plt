#include "CardRenderer.h"

using namespace render;
using namespace std;
/*
    sf::Texture texture;
    std::string name;
    std::shared_ptr<state::Ressources> cost;
    std::shared_ptr<state::Ressources> gain;
*/

CardRenderer::CardRenderer(std::shared_ptr<state::Card> card, sf::Vector2f position){
    this->setPosition(position);

    this->texture.loadFromFile("res/textures/brushed_alu_dark.png");
    
    this->name = card->name;
    this->cost = card->cost;
    this->gain = card->gain;
}

void CardRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Vector2f _position = this->getPosition();

    sf::Sprite _sprite(this->texture);
    _sprite.setScale(100/_sprite.getLocalBounds().width,130/_sprite.getLocalBounds().height);
    _sprite.setPosition(_position.x,_position.y);

    target.draw(_sprite);
}