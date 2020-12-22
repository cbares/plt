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

    this->font.loadFromFile("res/fonts/arial.ttf");
    
    this->name = card->name;
    this->cost = card->cost;
    this->gain = card->gain;
}

void CardRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Vector2f _position = this->getPosition();

    sf::Sprite _borderSprite(this->texture);
    _borderSprite.setScale(100/_borderSprite.getLocalBounds().width,130/_borderSprite.getLocalBounds().height);
    _borderSprite.setPosition(_position.x,_position.y);
    _borderSprite.setColor(sf::Color::Black);
    target.draw(_borderSprite);

    sf::Sprite _sprite(this->texture);
    _sprite.setScale(90/_sprite.getLocalBounds().width,120/_sprite.getLocalBounds().height);
    _sprite.setPosition(_position.x+5,_position.y+5);
    target.draw(_sprite);

    sf::Text _nameText(this->name,this->font, 15);
    _nameText.setPosition(_position.x+5,_position.y+5);
    target.draw(_nameText);
}