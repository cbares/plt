//
// Created by ensea on 13/11/22.
//
#include "MapDraw.hpp"


void render::MapDraw::generateMapPixel() {
    sf::CircleShape temphexa(24, 6);
    temphexa.rotate(90);
    temphexa.setOrigin({ temphexa.getRadius(), temphexa.getRadius() });

    for (int y = 0; y < 17 ; ++y) {
        std::vector<sf::Vector2f> temp;
        for (int x = 0; x < 10; ++x) {
            temphexa.setPosition(200 + y * 40.f , (y % 2 ? 50 : 75) + x * 50.f + 50);
            temp.push_back(temphexa.getPosition());
        }
        this->mapPixelPosition.push_back(temp);
    }
}

void render::MapDraw::generateMapPixelRemaining() {
    sf::CircleShape temphexar(24, 6);
    temphexar.rotate(90);
    temphexar.setOrigin({ temphexar.getRadius(), temphexar.getRadius() });
    for (int y = 0; y < 13 ; ++y) {
        std::vector<sf::Vector2f> temp;
        for (int x = 0; x < 1; ++x) {
            temphexar.setPosition(279 + y * 40.f , (y % 2 ? 50 : 75) + x * 50.f + 600);
            temp.push_back(temphexar.getPosition());
        }
        this->mapPixelRemainingPosition.push_back(temp);
    }
}

void render::MapDraw::setTilesShape() {
    sf::Color ruche = sf::Color(255,130,65,255);
    sf::CircleShape hexagon(24, 6);
    hexagon.setOutlineColor(sf::Color::White);
    hexagon.setOutlineThickness(2);
    hexagon.setFillColor(ruche);
    hexagon.rotate(90);
    hexagon.setOrigin({ hexagon.getRadius(), hexagon.getRadius() });
    this->tiles = hexagon;
}

int render::MapDraw::setBackground() {
    if (!background.loadFromFile("./res/backgroundqs.jpg"))
        return EXIT_FAILURE;
}

render::MapDraw::MapDraw() {
    setBackground();
    setTilesShape();
    generateMapPixel();
    generateMapPixelRemaining();
}

void render::MapDraw::initMapDraw(sf::RenderWindow &window) {
    sf::Sprite sfbg(background);
    window.draw(sfbg);

    for (int y = 0; y < 17 ; ++y) {
        for (int x = 0; x < 10; ++x) {
            this->tiles.setPosition(200 + y * 40.f , (y % 2 ? 50 : 75) + x * 50.f + 50);
            window.draw(tiles);
        }
    }
    for (int y = 0; y < 13 ; ++y) {
        for (int x = 0; x < 1; ++x) {
            this->tiles.setPosition(279 + y * 40.f , (y % 2 ? 50 : 75) + x * 50.f + 600);
            window.draw(this->tiles);
        }
    }
}



