
//
// Created by ensea on 13/11/22.
//
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



bool state::Game::IsBeeCircled(state::Player player) {

    bool result;

    if (player.GetColor()=="White"){
        for (Insect bee : player.Get_List_Insect_Played()){
            if (bee.GetName()=="Bee_W"){
                int i = bee.Get_Position()[0];int j=bee.Get_Position()[1];
                if((GameMap.GetListCase()[i-1][j].GetEmpty()== false)&&(GameMap.GetListCase()[i-1][j+1].GetEmpty()== false)&&(GameMap.GetListCase()[i][j-1].GetEmpty()== false)&&(GameMap.GetListCase()[i][j+1].GetEmpty()== false)&&(GameMap.GetListCase()[i+1][j].GetEmpty()== false)&&(GameMap.GetListCase()[i][j+1].GetEmpty()== false)){
                    result = true;
                }
                else {
                    result= false;
                }
            }
        }
    }

    if (player.GetColor()=="Black"){
        for (Insect bee : player.Get_List_Insect_Played()){
            if (bee.GetName()=="Bee_B"){
                int i = bee.Get_Position()[0];int j=bee.Get_Position()[1];
                if((GameMap.GetListCase()[i-1][j].GetEmpty()== false)&&(GameMap.GetListCase()[i-1][j+1].GetEmpty()== false)&&(GameMap.GetListCase()[i][j-1].GetEmpty()== false)&&(GameMap.GetListCase()[i][j+1].GetEmpty()== false)&&(GameMap.GetListCase()[i+1][j].GetEmpty()== false)&&(GameMap.GetListCase()[i][j+1].GetEmpty()== false)){
                    result = true;
                }
                else {
                    result= false;
                }
            }
        }
    }

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

state::Map state::Game::GetMap() {
    return this->GameMap;
}


void state::Game::AppendListJoueur(state::Player player) {
    this->listPlayer.push_back(player);
}

std::vector<state::Player> state::Game::GetListPlayer() {
    return this->listPlayer;
}





