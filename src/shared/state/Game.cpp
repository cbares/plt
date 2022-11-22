
//
// Created by ensea on 13/11/22.
//
#include "Game.hpp"
#include "Bee.hpp"
#include "Spider.hpp"
#include "Grasshooper.hpp"
#include "Beetle.hpp"


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

std::vector<state::Insect*> state::Game::GetAllInsects() {
    return this->ListeAllInsect;
}

void state::Game::AppendListInsect(state::Insect* insect) {

    this->ListeAllInsect.push_back(insect);

}



bool state::Game::IsBeeCircled(state::Player player) {

    bool result;

    if (player.GetColor()=="White"){
        for (Insect* bee : player.Get_List_Insect_Played()){
            if (bee->GetName()=="Bee_W"){
                int i = bee->Get_Position()[0];int j=bee->Get_Position()[1];
                if((GameMap.GetListCase()[i-1][j]->GetEmpty()== false)&&(GameMap.GetListCase()[i-1][j+1]->GetEmpty()== false)&&(GameMap.GetListCase()[i][j-1]->GetEmpty()== false)&&(GameMap.GetListCase()[i][j+1]->GetEmpty()== false)&&(GameMap.GetListCase()[i+1][j]->GetEmpty()== false)&&(GameMap.GetListCase()[i][j+1]->GetEmpty()== false)){
                    result = true;
                }
                else {
                    result= false;
                }
            }
        }
    }

    if (player.GetColor()=="Black"){
        for (Insect* bee : player.Get_List_Insect_Played()){
            if (bee->GetName()=="Bee_B"){
                int i = bee->Get_Position()[0];int j=bee->Get_Position()[1];
                if((GameMap.GetListCase()[i-1][j]->GetEmpty()== false)&&(GameMap.GetListCase()[i-1][j+1]->GetEmpty()== false)&&(GameMap.GetListCase()[i][j-1]->GetEmpty()== false)&&(GameMap.GetListCase()[i][j+1]->GetEmpty()== false)&&(GameMap.GetListCase()[i+1][j]->GetEmpty()== false)&&(GameMap.GetListCase()[i][j+1]->GetEmpty()== false)){
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
    Player player_white = *new Player("player_white","White");
    Player player_black = *new Player("player_black","Black");
    //Création des insectes
    //White
    Bee bee_white= *new Bee("Bee_White","White",{-99,-99},0);
    Spider spider_1_white=*new Spider("Spider_1_White","White",{-99,-99},0);
    Grasshooper grasshooper_1_white=*new Grasshooper("Grasshooper_1_White","White",{-99,-99},0);
    Beetle beetle_1_white=*new Beetle("Beetle_1_White","White",{-99,-99},0);
    //Black
    Bee bee_black=*new Bee("Bee_Black","Black",{-99,-99},0);
    Spider spider_1_black=*new Spider("Spider_1_Black","Black",{-99,-99},0);
    Grasshooper grasshooper_1_black=*new Grasshooper("Grasshooper_1_Black","Black",{-99,-99},0);
    Beetle beetle_1_black=*new Beetle("Beetle_1_Black","Black",{-99,-99},0);

    //Remplissage de la liste des insectes par joueur

    player_black.Add_Insect_Remaining(&bee_black);
    player_black.Add_Insect_Remaining(&spider_1_black);
    player_black.Add_Insect_Remaining(&grasshooper_1_black);
    player_black.Add_Insect_Remaining(&beetle_1_black);

    player_white.Add_Insect_Remaining(&bee_white);
    player_white.Add_Insect_Remaining(&spider_1_white);
    player_white.Add_Insect_Remaining(&grasshooper_1_white);
    player_white.Add_Insect_Remaining(&beetle_1_white);



//Remplissage de ListAllInsect
    for (int i=0; i<player_black.Get_List_Insect_Remaining().size();i++){
        ListeAllInsect.push_back(player_black.Get_List_Insect_Remaining()[i]);
    }
    for (int i=0; i<player_white.Get_List_Insect_Remaining().size();i++){
        ListeAllInsect.push_back(player_white.Get_List_Insect_Remaining()[i]);
    }


    //Remplissage de ListPlayer
    this->listPlayer.push_back(&player_white);
    this->listPlayer.push_back(&player_black);





}

state::Map state::Game::GetMap() {
    return this->GameMap;
}


void state::Game::AppendListJoueur(state::Player* player) {
    this->listPlayer.push_back(player);
}

std::vector<state::Player*> state::Game::GetListPlayer() {
    return this->listPlayer;
}





