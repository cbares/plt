
//
// Created by ensea on 13/11/22.
//
#include "Game.hpp"
#include "Bee.hpp"

using namespace std;
using namespace state;

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

void state::Game::AppendListInsect(state::Insect& insect) {

    this->ListeAllInsect.push_back(&insect);

}



bool state::Game::IsBeeCircled(state::Player player) {

    bool result;

    if (player.GetColor() == "White") {

        for (auto bee: player.Get_List_Insect_Played()) {
            if (bee->GetName() == "Bee_B") {
                int i = bee->Get_Position()[0];
                int j = bee->Get_Position()[1];
                if (j % 2 == 0) {
                    if ((GameMap->GetListCase()[i][j - 1].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i][j + 1].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i - 1][j].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i + 1][j - 1].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i + 1][j].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i + 1][j + 1].GetEmpty() == false)) {
                        result = true;
                    }
                } else {
                    if ((GameMap->GetListCase()[i - 1][j].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i - 1][j + 1].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i][j - 1].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i][j + 1].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i + 1][j].GetEmpty() == false) &&
                        (GameMap->GetListCase()[i][j + 1].GetEmpty() == false)) {
                        result = true;
                    } else {
                        result = false;
                    }
                }
            }
        }
    }


            if (player.GetColor() == "Black") {
                for (auto bee: player.Get_List_Insect_Played()) {
                    if (bee->GetName() == "Bee_A") {
                        int i = bee->Get_Position()[0];
                        int j = bee->Get_Position()[1];
                        if (j % 2 == 0) {
                            if ((GameMap->GetListCase()[i][j - 1].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i][j + 1].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i - 1][j].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i + 1][j - 1].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i + 1][j].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i + 1][j + 1].GetEmpty() == false)) {
                                result = true;
                            }
                        } else {
                            if ((GameMap->GetListCase()[i - 1][j].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i - 1][j + 1].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i][j - 1].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i][j + 1].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i + 1][j].GetEmpty() == false) &&
                                (GameMap->GetListCase()[i][j + 1].GetEmpty() == false)) {
                                result = true;
                            }


                        else {
                            result = false;
                        }
                        }
                    }
                }
            }

    return result;
}

state::Game::Game() {
    this->nbIteration=0; //On commence au tour 0
    this->state=Player_A_playing; //choix arbitraire
    this->GameMap= new Map(10,17); //Map de 10 x 10 cases

}

state::Map* state::Game::GetMap() {
    return this->GameMap;
}


void state::Game::AppendListJoueur(state::Player& player) {
    this->listPlayer.push_back(&player);
}

std::vector<state::Player *> state::Game::GetListPlayer() {
    return this->listPlayer;
}

vector<state::Insect> Game::GetAllInsect_placed() {

    vector<Insect> list_res;

    for (auto ins : this->ListeAllInsect){
        if (ins->GetIsPlaced()){
            list_res.push_back(*ins);
        }
    }


    return list_res;
}





