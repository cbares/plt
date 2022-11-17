//
// Created by ensea on 13/11/22.
//
#include "Scene.hpp"

render::Scene::Scene(state::Game state) {
    this->mapDraw = MapDraw();
    this->insectDraw = InsectDraw(this->mapDraw.mapPixelPosition,this->mapDraw.mapPixelRemainingPosition);
    this->textDraw = TextDraw(state);
}

void render::Scene::drawScene(state::Game state, sf::RenderWindow &window) {
    this->mapDraw.initMapDraw(window);
    this->insectDraw.drawInsect(window,state);
    this->textDraw.drawText(window,state);
}


