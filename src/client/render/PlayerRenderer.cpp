#include "PlayerRenderer.h"

using namespace render;
using namespace std;

std::string dif2string(int ressource){
    if(ressource>=0){
        return string("+") + to_string(ressource);
    }
    else{
        return to_string(ressource);
    }
}

PlayerRenderer::PlayerRenderer(std::shared_ptr<state::Player> player, sf::Vector2f position){
    this->setPosition(position);
    
    this->name = player->name;

    this->ressources = make_shared<state::Ressources>(player->ressources->serialize());

    this->texture.loadFromFile("res/textures/denim.png");

    this->font.loadFromFile("res/fonts/arial.ttf");
}

void PlayerRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Vector2f _position = this->getPosition();

    sf::Sprite _sprite(this->texture);
    _sprite.setScale(400/_sprite.getLocalBounds().width,499/_sprite.getLocalBounds().height);
    _sprite.setPosition(_position.x,_position.y);

    target.draw(_sprite);

    sf::Text _nameText(string("Player :") + this->name,this->font, 30);
    
    _nameText.setPosition(_position.x+10,_position.y+30);
    target.draw(_nameText);

    sf::Text _stoneText(string("Stone :") + to_string(this->ressources->stone) + 
                    string("(") + dif2string(this->ressources->stoneIncome) + string(")\n"),this->font, 30);
    
    _stoneText.setPosition(_position.x+10,_position.y+90);
    target.draw(_stoneText);
    
    
    sf::Text _woodText(string("wood :") + to_string(this->ressources->wood) + 
                    string("(") + dif2string(this->ressources->woodIncome) + string(")\n"),this->font, 30);

    _woodText.setPosition(_position.x+10,_position.y+150);
    target.draw(_woodText);

    sf::Text _waterText(string("water :") + to_string(this->ressources->water) + 
                    string("(") + dif2string(this->ressources->waterIncome) + string(")\n"),this->font, 30);

    _waterText.setPosition(_position.x+10,_position.y+210);
    target.draw(_waterText);

    sf::Text _victoryPointText(string("VictoryPoint :") + to_string(this->ressources->victoryPoint) + 
                    string("(") + dif2string(this->ressources->victoryPointIncome) + string(")\n"),this->font, 30);

    _victoryPointText.setPosition(_position.x+10,_position.y+270);
    target.draw(_victoryPointText);
}