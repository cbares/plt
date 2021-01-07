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

    this->texture.loadFromFile("res/textures/playerSprite.png");

    this->font.loadFromFile("res/fonts/arial.ttf");

    sf::Texture _waterTexture;
    _waterTexture.loadFromFile("res/textures/waterToken.png");
    _waterTexture.setSmooth(true);
    this->ressourcesTextures["water"] = _waterTexture;
    sf::Texture _stoneTexture;
    _stoneTexture.loadFromFile("res/textures/stoneToken.png");
    _stoneTexture.setSmooth(true);
    this->ressourcesTextures["stone"] = _stoneTexture;
    sf::Texture _woodTexture;
    _woodTexture.loadFromFile("res/textures/woodToken.png");
    _woodTexture.setSmooth(true);
    this->ressourcesTextures["wood"] = _woodTexture;
    sf::Texture _crownTexture;
    _crownTexture.loadFromFile("res/textures/victoryToken.png");
    _crownTexture.setSmooth(true);
    this->ressourcesTextures["crown"] = _crownTexture;

    sf::Texture _waterTextureInc;
    _waterTextureInc.loadFromFile("res/textures/waterTokenInc.png");
    _waterTextureInc.setSmooth(true);
    this->ressourcesTextures["waterInc"] = _waterTextureInc;
    sf::Texture _stoneTextureInc;
    _stoneTextureInc.loadFromFile("res/textures/stoneTokenInc.png");
    _stoneTextureInc.setSmooth(true);
    this->ressourcesTextures["stoneInc"] = _stoneTextureInc;
    sf::Texture _woodTextureInc;
    _woodTextureInc.loadFromFile("res/textures/woodTokenInc.png");
    _woodTextureInc.setSmooth(true);
    this->ressourcesTextures["woodInc"] = _woodTextureInc;
    sf::Texture _crownTextureInc;
    _crownTextureInc.loadFromFile("res/textures/victoryTokenInc.png");
    _crownTextureInc.setSmooth(true);
    this->ressourcesTextures["crownInc"] = _crownTextureInc;
}

void PlayerRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Vector2f _position = this->getPosition();

    sf::Sprite _sprite(this->texture);
    _sprite.setScale(400/_sprite.getLocalBounds().width,400/_sprite.getLocalBounds().height);
    _sprite.setPosition(_position.x,_position.y);

    _position += sf::Vector2f(35,37);

    target.draw(_sprite);

    sf::Text _nameText(this->name,this->font, 40);
    _nameText.setColor(sf::Color::Black);
    _nameText.setPosition(_position.x,_position.y);
    target.draw(_nameText);

    sf::Color darkgreen(0,147,0,255);

    sf::Vector2f _positionRes;
    _positionRes = _position + sf::Vector2f(0,90);


    sf::Sprite _stoneSprite(this->ressourcesTextures.find("stone")->second);
    _stoneSprite.setScale(50/_stoneSprite.getLocalBounds().width,50/_stoneSprite.getLocalBounds().height);
    _stoneSprite.setPosition(_positionRes.x,_positionRes.y);
    target.draw(_stoneSprite);

    sf::Text _stoneText(to_string(this->ressources->stone) + string("\n"),this->font, 30);
    _stoneText.setPosition(_positionRes + sf::Vector2f(_stoneSprite.getGlobalBounds().width + 10,5));
    _stoneText.setColor(sf::Color::Black);
    target.draw(_stoneText);

    sf::Sprite _stoneSpriteInc(this->ressourcesTextures.find("stoneInc")->second);
    _stoneSpriteInc.setScale(50/_stoneSpriteInc.getLocalBounds().width,50/_stoneSpriteInc.getLocalBounds().height);
    _stoneSpriteInc.setPosition(_positionRes.x + 125,_positionRes.y);
    target.draw(_stoneSpriteInc);

    sf::Text _stoneTextInc(dif2string(this->ressources->stoneIncome) + string("\n"),this->font, 30);
    _stoneTextInc.setPosition(_positionRes + sf::Vector2f(125 + _stoneSpriteInc.getGlobalBounds().width + 10,5));
    _stoneTextInc.setColor(darkgreen);
    target.draw(_stoneTextInc);

    _positionRes = sf::Vector2f(_positionRes.x,_stoneText.getGlobalBounds().top+_stoneText.getGlobalBounds().height);
    

    sf::Sprite _woodSprite(this->ressourcesTextures.find("wood")->second);
    _woodSprite.setScale(50/_woodSprite.getLocalBounds().width,50/_woodSprite.getLocalBounds().height);
    _woodSprite.setPosition(_positionRes.x,_positionRes.y);
    target.draw(_woodSprite);

    sf::Text _woodText(to_string(this->ressources->wood) + string("\n"),this->font, 30);
    _woodText.setPosition(_positionRes + sf::Vector2f(_woodSprite.getGlobalBounds().width + 10,5));
    _woodText.setColor(sf::Color::Black);
    target.draw(_woodText);

    sf::Sprite _woodSpriteInc(this->ressourcesTextures.find("woodInc")->second);
    _woodSpriteInc.setScale(50/_woodSpriteInc.getLocalBounds().width,50/_woodSpriteInc.getLocalBounds().height);
    _woodSpriteInc.setPosition(_positionRes.x + 125,_positionRes.y);
    target.draw(_woodSpriteInc);

    sf::Text _woodTextInc(dif2string(this->ressources->woodIncome) + string("\n"),this->font, 30);
    _woodTextInc.setPosition(_positionRes + sf::Vector2f(125 + _woodSpriteInc.getGlobalBounds().width + 10,5));
    _woodTextInc.setColor(darkgreen);
    target.draw(_woodTextInc);

    _positionRes = sf::Vector2f(_positionRes.x,_woodText.getGlobalBounds().top+_woodText.getGlobalBounds().height);


    sf::Sprite _waterSprite(this->ressourcesTextures.find("water")->second);
    _waterSprite.setScale(50/_waterSprite.getLocalBounds().width,50/_waterSprite.getLocalBounds().height);
    _waterSprite.setPosition(_positionRes.x,_positionRes.y);
    target.draw(_waterSprite);

    sf::Text _waterText(to_string(this->ressources->water) + string("\n"),this->font, 30);
    _waterText.setPosition(_positionRes + sf::Vector2f(_waterSprite.getGlobalBounds().width + 10,5));
    _waterText.setColor(sf::Color::Black);
    target.draw(_waterText);

    sf::Sprite _waterSpriteInc(this->ressourcesTextures.find("waterInc")->second);
    _waterSpriteInc.setScale(50/_waterSpriteInc.getLocalBounds().width,50/_waterSpriteInc.getLocalBounds().height);
    _waterSpriteInc.setPosition(_positionRes.x + 125,_positionRes.y);
    target.draw(_waterSpriteInc);

    sf::Text _waterTextInc(dif2string(this->ressources->waterIncome) + string("\n"),this->font, 30);
    _waterTextInc.setPosition(_positionRes + sf::Vector2f(125 + _waterSpriteInc.getGlobalBounds().width + 10,5));
    _waterTextInc.setColor(darkgreen);
    target.draw(_waterTextInc);

    _positionRes = sf::Vector2f(_positionRes.x,_waterText.getGlobalBounds().top+_waterText.getGlobalBounds().height);



    sf::Sprite _victoryPointSprite(this->ressourcesTextures.find("crown")->second);
    _victoryPointSprite.setScale(50/_victoryPointSprite.getLocalBounds().width,50/_victoryPointSprite.getLocalBounds().height);
    _victoryPointSprite.setPosition(_positionRes.x,_positionRes.y);
    target.draw(_victoryPointSprite);

    sf::Text _victoryPointText(to_string(this->ressources->victoryPoint) + string("\n"),this->font, 30);
    _victoryPointText.setPosition(_positionRes + sf::Vector2f(_victoryPointSprite.getGlobalBounds().width + 10,5));
    _victoryPointText.setColor(sf::Color::Black);
    target.draw(_victoryPointText);

    sf::Sprite _victoryPointSpriteInc(this->ressourcesTextures.find("crownInc")->second);
    _victoryPointSpriteInc.setScale(50/_victoryPointSpriteInc.getLocalBounds().width,50/_victoryPointSpriteInc.getLocalBounds().height);
    _victoryPointSpriteInc.setPosition(_positionRes.x + 125,_positionRes.y);
    target.draw(_victoryPointSpriteInc);

    sf::Text _victoryPointTextInc(dif2string(this->ressources->victoryPointIncome) + string("\n"),this->font, 30);
    _victoryPointTextInc.setPosition(_positionRes + sf::Vector2f(125 + _victoryPointSpriteInc.getGlobalBounds().width + 10,5));
    _victoryPointTextInc.setColor(darkgreen);
    target.draw(_victoryPointTextInc);


}