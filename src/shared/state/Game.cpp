#include "Game.hpp"


void state::Game::UpdateState(state::GameStatus state) {
    this->state=state;
}

void state::Game::IncrementIteration() {
    this->nbIteration ++;
}

state::GameStatus state::Game::GetState() {
    return this->state;
}

int state::Game::GetIteration() {
    return this->nbIteration;
}

void state::Game::SetIteration(int param) {
this->nbIteration=param;
}

std::vector<state::Insect> state::Game::GetAllInsects() {
    return this->ListeAllInsect;
}

void state::Game::AppendListInsect(state::Insect insect) {
this->ListeAllInsect.push_back(insect);
}

void state::Game::Display_Possible_Moves(std::vector<std::vector<int>> ListMoves) {

}

bool state::Game::IsBeeCircled(state::Player player) {

    bool result;

    //Recherche de l'abeille du joueur
    std::vector<Insect> listins =player.Get_List_Insect_Played();


    return result;
}

state::Game::Game() {
    this->nbIteration=0; //On commence au tour 0
    this->state=Player_A_playing; //choix arbitraire
    this->GameMap=Map(10,10); //Map de 10 x 10 cases

//Création des joueurs
    Player player_white = Player("player_white","White");
    Player player_black = Player("player_black","Black");

//Remplissage de ListAllInsect
    for (int i=0; i<player_black.Get_List_Insect_Remaining().size();i++){
        ListeAllInsect.push_back(player_black.Get_List_Insect_Remaining()[i]);
    }
    for (int i=0; i<player_white.Get_List_Insect_Remaining().size();i++){
        ListeAllInsect.push_back(player_white.Get_List_Insect_Remaining()[i]);
    }

}



