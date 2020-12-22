#include "CardRenderer.h"
#include <iostream>
#include <stdio.h>
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

void CardRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Vector2f _position = this->getPosition();

    sf::Sprite _borderSprite(this->texture);
    _borderSprite.setScale(100/_borderSprite.getLocalBounds().width,130/_borderSprite.getLocalBounds().height);
    _borderSprite.setPosition(_position.x,_position.y);
    _borderSprite.setColor(sf::Color::Black);
    target.draw(_borderSprite);

    _position += sf::Vector2f(5,5);
    // Card name part
    sf::Sprite _backgroundSprite(this->texture);
    _backgroundSprite.setScale(90/_backgroundSprite.getLocalBounds().width,120/_backgroundSprite.getLocalBounds().height);
    _backgroundSprite.setPosition(_position.x,_position.y);
    target.draw(_backgroundSprite);

    sf::Text _nameText(this->name,this->font, 15);
    _nameText.setPosition(_position.x+3,_position.y);
    target.draw(_nameText);

    _position += sf::Vector2f(0,20);

    // Card cost part

    if(cost->stone !=0){
        sf::Text _text(to_string(this->cost->stone),this->font, 15);
        _text.setPosition(_position.x,_position.y);
        target.draw(_text);
        _position += sf::Vector2f(_text.getLocalBounds().width,0);
        sf::Sprite _spriteStone(this->ressourcesTextures.find("stone")->second);
        _spriteStone.setScale(15.36/_spriteStone.getLocalBounds().width,15.36/_spriteStone.getLocalBounds().height);
        _spriteStone.setPosition(_position.x,_position.y+2);
        target.draw(_spriteStone);
        _position += sf::Vector2f(_spriteStone.getGlobalBounds().width,0);
    }
    if(cost->wood !=0){
        sf::Text _text(to_string(this->cost->wood),this->font, 15);
        _text.setPosition(_position.x,_position.y);
        target.draw(_text);
        _position += sf::Vector2f(_text.getLocalBounds().width,0);
        sf::Sprite _spriteWood(this->ressourcesTextures.find("wood")->second);
        _spriteWood.setScale(15.36/_spriteWood.getLocalBounds().width,15.36/_spriteWood.getLocalBounds().height);
        _spriteWood.setPosition(_position.x,_position.y+2);
        target.draw(_spriteWood);
        _position += sf::Vector2f(_spriteWood.getGlobalBounds().width,0);
    }
    if(cost->water !=0){
        sf::Text _text(to_string(this->cost->water),this->font, 15);
        _text.setPosition(_position.x,_position.y);
        target.draw(_text);
        _position += sf::Vector2f(_text.getLocalBounds().width,0);
        sf::Sprite _spriteWater(this->ressourcesTextures.find("water")->second);
        _spriteWater.setScale(15.36/_spriteWater.getLocalBounds().width,15.36/_spriteWater.getLocalBounds().height);
        _spriteWater.setPosition(_position.x,_position.y+2);
        target.draw(_spriteWater);
        _position += sf::Vector2f(_spriteWater.getGlobalBounds().width,0);
    }

    _position = sf::Vector2f(this->getPosition().x+5,_position.y+40);

    // Card gain part
    if(gain->stone !=0){
        sf::Text _text(string("Gain ") + to_string(this->gain->stone),this->font, 15);
        _text.setPosition(_position.x,_position.y);
        target.draw(_text);
        _position += sf::Vector2f(_text.getLocalBounds().width,0);
        sf::Sprite _stoneSprite(this->ressourcesTextures.find("stone")->second);
        _stoneSprite.setScale(15.36/_stoneSprite.getLocalBounds().width,15.36/_stoneSprite.getLocalBounds().height);
        _stoneSprite.setPosition(_position.x,_position.y+2);
        target.draw(_stoneSprite);
        _position += sf::Vector2f(_stoneSprite.getGlobalBounds().width,0);
    }

    if(gain->stoneIncome !=0){
        cout << gain->stoneIncome << endl;
        sf::Text _text(string("Gain ") + to_string(this->gain->stoneIncome),this->font, 15);
        _text.setPosition(_position.x,_position.y);
        target.draw(_text);
        _position += sf::Vector2f(_text.getGlobalBounds().width,0);
        sf::Sprite _stoneSprite(this->ressourcesTextures.find("stone")->second);
        _stoneSprite.setScale(15.36/_stoneSprite.getLocalBounds().width,15.36/_stoneSprite.getLocalBounds().height);
        _stoneSprite.setPosition(_position.x,_position.y+2);
        target.draw(_stoneSprite);
        _position += sf::Vector2f(_stoneSprite.getGlobalBounds().width,0);
        sf::Text _text2(string(" per turn"),this->font, 15);
        _text2.setPosition(_position.x,_position.y);
        target.draw(_text2);
    }

    if(gain->water !=0){
        sf::Text _text(string("Gain ") + to_string(this->gain->water),this->font, 15);
        _text.setPosition(_position.x,_position.y);
        target.draw(_text);
        _position += sf::Vector2f(_text.getLocalBounds().width,0);
        sf::Sprite _waterSprite(this->ressourcesTextures.find("water")->second);
        _waterSprite.setScale(15.36/_waterSprite.getLocalBounds().width,15.36/_waterSprite.getLocalBounds().height);
        _waterSprite.setPosition(_position.x,_position.y+2);
        target.draw(_waterSprite);
        _position += sf::Vector2f(_waterSprite.getGlobalBounds().width,0);
    }
    if(gain->wood !=0){
        sf::Text _text(string("Gain ") + to_string(this->gain->wood),this->font, 15);
        _text.setPosition(_position.x,_position.y);
        target.draw(_text);
        _position += sf::Vector2f(_text.getLocalBounds().width,0);
        sf::Sprite _woodSprite(this->ressourcesTextures.find("wood")->second);
        _woodSprite.setScale(15.36/_woodSprite.getLocalBounds().width,15.36/_woodSprite.getLocalBounds().height);
        _woodSprite.setPosition(_position.x,_position.y+2);
        target.draw(_woodSprite);
        _position += sf::Vector2f(_woodSprite.getGlobalBounds().width,0);
    }
    if(gain->victoryPoint !=0){
        sf::Text _text(string("Gain ") + to_string(this->gain->victoryPoint),this->font, 15);
        _text.setPosition(_position.x,_position.y);
        target.draw(_text);
        _position += sf::Vector2f(_text.getLocalBounds().width,0);
        sf::Sprite _victoryPointSprite(this->ressourcesTextures.find("crown")->second);
        _victoryPointSprite.setScale(15.36/_victoryPointSprite.getLocalBounds().width,15.36/_victoryPointSprite.getLocalBounds().height);
        _victoryPointSprite.setPosition(_position.x,_position.y+2);
        target.draw(_victoryPointSprite);
        _position += sf::Vector2f(_victoryPointSprite.getGlobalBounds().width,0);
    }

}