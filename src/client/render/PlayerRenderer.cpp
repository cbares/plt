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

    sf::Texture _waterTexture;
    _waterTexture.loadFromFile("res/textures/water.png");
    _waterTexture.setSmooth(true);
    this->ressourcesTextures["water"] = _waterTexture;
    sf::Texture _stoneTexture;
    _stoneTexture.loadFromFile("res/textures/stone.png");
    _stoneTexture.setSmooth(true);
    this->ressourcesTextures["stone"] = _stoneTexture;
    sf::Texture _woodTexture;
    _woodTexture.loadFromFile("res/textures/wood.png");
    _woodTexture.setSmooth(true);
    this->ressourcesTextures["wood"] = _woodTexture;
    sf::Texture _crownTexture;
    _crownTexture.loadFromFile("res/textures/crown.png");
    _crownTexture.setSmooth(true);
    this->ressourcesTextures["crown"] = _crownTexture;
}

void PlayerRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Vector2f _position = this->getPosition();

    sf::Sprite _sprite(this->texture);
    _sprite.setScale(400/_sprite.getLocalBounds().width,400/_sprite.getLocalBounds().height);
    _sprite.setPosition(_position.x,_position.y);

    _position += sf::Vector2f(10,30);

    target.draw(_sprite);

    sf::Text _nameText(string("Player :") + this->name,this->font, 30);
    _nameText.setPosition(_position.x,_position.y);
    target.draw(_nameText);

    _position += sf::Vector2f(0,90);

    sf::Sprite _stoneSprite(this->ressourcesTextures.find("stone")->second);
    _stoneSprite.setScale(50/_stoneSprite.getLocalBounds().width,50/_stoneSprite.getLocalBounds().height);
    _stoneSprite.setPosition(_position.x,_position.y);
    target.draw(_stoneSprite);

    _position += sf::Vector2f(_stoneSprite.getGlobalBounds().width,0);
    sf::Text _stoneText(to_string(this->ressources->stone) + 
                    string("(") + dif2string(this->ressources->stoneIncome) + string(")\n"),this->font, 30);
    _stoneText.setPosition(_position.x,_position.y);
    target.draw(_stoneText);

    _position = sf::Vector2f(this->getPosition().x+10,_stoneText.getGlobalBounds().top+_stoneText.getGlobalBounds().height+10);
    

    sf::Sprite _woodSprite(this->ressourcesTextures.find("wood")->second);
    _woodSprite.setScale(50/_woodSprite.getLocalBounds().width,50/_woodSprite.getLocalBounds().height);
    _woodSprite.setPosition(_position.x,_position.y);
    target.draw(_woodSprite);

    _position += sf::Vector2f(_woodSprite.getGlobalBounds().width,0);
    sf::Text _woodText(to_string(this->ressources->wood) + 
                    string("(") + dif2string(this->ressources->woodIncome) + string(")\n"),this->font, 30);
    _woodText.setPosition(_position.x,_position.y);
    target.draw(_woodText);

    _position = sf::Vector2f(this->getPosition().x+10,_woodText.getGlobalBounds().top+_woodText.getGlobalBounds().height+10);

    sf::Sprite _waterSprite(this->ressourcesTextures.find("water")->second);
    _waterSprite.setScale(50/_waterSprite.getLocalBounds().width,50/_waterSprite.getLocalBounds().height);
    _waterSprite.setPosition(_position.x,_position.y);
    target.draw(_waterSprite);

    _position += sf::Vector2f(_waterSprite.getGlobalBounds().width,0);
    sf::Text _waterText(to_string(this->ressources->water) + 
                    string("(") + dif2string(this->ressources->waterIncome) + string(")\n"),this->font, 30);
    _waterText.setPosition(_position.x,_position.y);
    target.draw(_waterText);

    _position = sf::Vector2f(this->getPosition().x+10,_waterSprite.getGlobalBounds().top+_waterSprite.getGlobalBounds().height+10);

    sf::Sprite _victoryPointSprite(this->ressourcesTextures.find("crown")->second);
    _victoryPointSprite.setScale(50/_victoryPointSprite.getLocalBounds().width,50/_victoryPointSprite.getLocalBounds().height);
    _victoryPointSprite.setPosition(_position.x,_position.y);
    target.draw(_victoryPointSprite);

    _position += sf::Vector2f(_victoryPointSprite.getGlobalBounds().width,0);
    sf::Text __victoryPointText(to_string(this->ressources->victoryPoint) + 
                    string("(") + dif2string(this->ressources->victoryPointIncome) + string(")\n"),this->font, 30);
    __victoryPointText.setPosition(_position.x,_position.y);
    target.draw(__victoryPointText);

    _position = sf::Vector2f(this->getPosition().x+10,_victoryPointSprite.getGlobalBounds().top+_victoryPointSprite.getGlobalBounds().height+10);

}