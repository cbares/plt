//
// Created by ensea on 14/11/22.
//
#include"TextDraw.hpp"
#include <sstream>

render::TextDraw::TextDraw() = default;

void render::TextDraw::drawText(sf::RenderWindow &window, state::Game state) {


    std::stringstream pname;
    std::stringstream ntour;

    pname << "P1" << p1 <<"\n"
       << "P2" << p2 << "\n";
    playerName.setString(pname.str());
    pname << "Turn" << state.GetIteration();
    nbtour.setString(pname.str());

    window.draw(playerName);
    window.draw(nbtour);

}

void render::TextDraw::getPlayerName(state::Game state) {
    this->listPlayer = state.GetListPlayer();
    p1 = listPlayer[0].GetName();
    p2 = listPlayer[1].GetName();
}

render::TextDraw::TextDraw(state::Game state) {
    font.loadFromFile("/home/ensea/CLionProjects/plt/res/arial.ttf");

    this->nbtour = sf::Text();
    //this->nbtour = sf::Text("",font,20);
    //nbtour.setFont(font);
    nbtour.setCharacterSize(20);
    nbtour.setPosition(980,400);

    this->playerName = sf::Text();
    //playerName.setFont(font);
    playerName.setCharacterSize(20);
    playerName.setPosition(980,200);

    //getPlayerName(state);

}
