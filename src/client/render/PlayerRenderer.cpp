#include "PlayerRenderer.h"

using namespace render;
using namespace std;

/*
    sf::Texture texture;
    sf::Font font;
    std::shared_ptr<state::Ressources> ressouces;
*/

PlayerRenderer::PlayerRenderer(std::shared_ptr<state::Player> player, sf::Vector2f position){
    this->setPosition(position);

    this->ressources = make_shared<state::Ressources>(player->ressources->serialize());

    this->texture.loadFromFile("res/textures/denim.png");

    this->font.loadFromFile("res/fonts/arial.ttf");
}

void PlayerRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Vector2f _position = this->getPosition();

    sf::Sprite _sprite(this->texture);
    _sprite.setScale(400/_sprite.getLocalBounds().width,499/_sprite.getLocalBounds().height);
    _sprite.setPosition(_position.x,_position.y);

    sf::Text _text(string("Player \n") + 
                    string("Stone :") + std::to_string(this->ressources->stone)+ 
                    string("Stone :") + std::to_string(this->ressources->stone)+ 
                    string("Stone :") + std::to_string(this->ressources->stone)+ 
                    string("Stone :") + std::to_string(this->ressources->stone)+ 
                    string("Stone :") + std::to_string(this->ressources->stone)+ 
                    string("Stone :") + std::to_string(this->ressources->stone)+ 
                    string("Stone :") + std::to_string(this->ressources->stone)+ 
                    string("Stone :") + std::to_string(this->ressources->stone)
                    ,this->font, 30);
    _text.setPosition(_position.x+10,_position.y);
    
    target.draw(_sprite);
    target.draw(_text);
}