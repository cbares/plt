//
// Created by ensea on 14/11/22.
//
#include"TextDraw.hpp"
#include <sstream>

render::TextDraw::TextDraw() {
    font.loadFromFile("/home/ensea/CLionProjects/plt/res/arial.ttf");

   /* this->nbtour = sf::Text();
    nbtour.setCharacterSize(20);
    nbtour.setPosition(980,400);

    this->playerName = sf::Text();
    playerName.setCharacterSize(20);
    playerName.setPosition(980,200);*/
}

void render::TextDraw::drawText(sf::RenderWindow &window, state::Game state) {

    std::stringstream pname;
    std::stringstream ntour;

    getPlayerName(state);
    this->nbtour = sf::Text("",font,20);
    nbtour.setFont(font);
    this->playerName = sf::Text("",font,20);
    playerName.setFont(font);

    this->nbtour.setCharacterSize(20);
    this->nbtour.setPosition(900,280);

    this->playerName.setCharacterSize(20);
    playerName.setPosition(900,200);

    pname << "P1: " << p1 <<"\n"
       << "P2: " << p2 << "\n";
    playerName.setString(pname.str());
    ntour << "Turn: " << state.GetIteration();
    nbtour.setString(ntour.str());

    window.draw(playerName);
    window.draw(nbtour);

}

void render::TextDraw::getPlayerName(state::Game state) {
    this->listPlayer = state.GetListPlayer();
    p1 = listPlayer[0].GetName();
    p2 = listPlayer[1].GetName();
}

render::TextDraw::TextDraw(state::Game state) {

    //getPlayerName(state);

}
