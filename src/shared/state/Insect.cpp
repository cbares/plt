//
// Created by ensea on 30/10/22.
//
#include "Insect.hpp"
#include "Case.hpp"

using namespace std;
using namespace state;

Insect::Insect(std::string name, std::string color, std::vector<int> coord, int level) {
    this->Name = name;
    this->Color = color;
    this->Coord = {-1,-1};
    this->Level = 0;
    this->IsPlaced = 0;
}

string Insect::GetName() {
    return this->Name;
}

string Insect::GetColor() {
    return this->Color;
}

int Insect::GetLevel() {
    return Level;
}

void Insect::SetPosition(std::vector<int> coord) {
    this->Coord = coord;
}

void Insect::SetLevel(int level) {
    this->Level = level;
}

bool Insect::GetIsPlaced() {
    return this->IsPlaced;
}

void Insect::SetIsPlaced(bool state) {
    this->IsPlaced = state;
}

std::vector<int> Insect::Get_Position() {
    return this->Coord;
}

std::vector<std::vector<int>>
Insect::Possible_Placement_Insect(std::vector<Insect> list_insect_placed, std::vector<Case> list_case) {

    std::vector<std::vector<int>> list_possible_placement;
    vector<Insect> Allies_Insect;

    // Si aucun insecte est posé //on peut poser partout
    if (list_insect_placed.size()==0){
        for (Case temp : list_case){
            list_possible_placement.push_back(temp.GetPosition());
        }
        return list_possible_placement;
    }


    //Recherche des insectes alliés
    for (Insect temp : list_insect_placed){
        if(temp.GetColor()==this->Color) {
            Allies_Insect.push_back(temp);
        }
    }

    //Si aucun insecte allié est posé //correspond à l'étape du 2ème joueur au tour 1
    if (Allies_Insect.size()==0){ //donc il n'y a qu'un pion
        for(Insect temp : list_insect_placed){
            int i = temp.Get_Position()[0];
            int j = temp.Get_Position()[1];

            for (Case casetemp:list_case){
                if((casetemp.GetPosition()[0]==i-1)&&(casetemp.GetPosition()[1]==j)&&(casetemp.GetEmpty()== true)){
                    list_possible_placement.push_back(casetemp.GetPosition());
                }
                else if((casetemp.GetPosition()[0]==i-1)&&(casetemp.GetPosition()[1]==j+1)&&(casetemp.GetEmpty()== true)){
                    list_possible_placement.push_back(casetemp.GetPosition());
                }
                else if ((casetemp.GetPosition()[0]==i)&&(casetemp.GetPosition()[1]==j-1)&&(casetemp.GetEmpty()== true)){
                    list_possible_placement.push_back(casetemp.GetPosition());
                }
                else if ((casetemp.GetPosition()[0]==i)&&(casetemp.GetPosition()[1]==j+1)&&(casetemp.GetEmpty()== true)){
                    list_possible_placement.push_back(casetemp.GetPosition());
                }
                else if ((casetemp.GetPosition()[0]==i+1)&&(casetemp.GetPosition()[1]==j)&&(casetemp.GetEmpty()== true)){
                    list_possible_placement.push_back(casetemp.GetPosition());
                }
                else if ((casetemp.GetPosition()[0]==i+1)&&(casetemp.GetPosition()[1]==j+1)&&(casetemp.GetEmpty()== true)){
                    list_possible_placement.push_back(casetemp.GetPosition());
                }
            }
        }
        return list_possible_placement;
    }



    //Cette partie concerne donc les autres cas
    for (Insect temp: Allies_Insect){
        int i = temp.Get_Position()[0];
        int j = temp.Get_Position()[1];

        for (Case casetemp:list_case){
            if((casetemp.GetPosition()[0]==i-1)&&(casetemp.GetPosition()[1]==j)&&(casetemp.GetEmpty()== true)){
                list_possible_placement.push_back(casetemp.GetPosition());
            }
            else if((casetemp.GetPosition()[0]==i-1)&&(casetemp.GetPosition()[1]==j+1)&&(casetemp.GetEmpty()== true)){
                list_possible_placement.push_back(casetemp.GetPosition());
            }
            else if ((casetemp.GetPosition()[0]==i)&&(casetemp.GetPosition()[1]==j-1)&&(casetemp.GetEmpty()== true)){
                list_possible_placement.push_back(casetemp.GetPosition());
            }
            else if ((casetemp.GetPosition()[0]==i)&&(casetemp.GetPosition()[1]==j+1)&&(casetemp.GetEmpty()== true)){
                list_possible_placement.push_back(casetemp.GetPosition());
            }
            else if ((casetemp.GetPosition()[0]==i+1)&&(casetemp.GetPosition()[1]==j)&&(casetemp.GetEmpty()== true)){
                list_possible_placement.push_back(casetemp.GetPosition());
            }
            else if ((casetemp.GetPosition()[0]==i+1)&&(casetemp.GetPosition()[1]==j+1)&&(casetemp.GetEmpty()== true)){
                list_possible_placement.push_back(casetemp.GetPosition());
            }
        }
    }

//RECHERCHE DES DOUBLONS DANS LA LISTES DES COORDONNEES POSSIBLES
    vector<vector<int>> list_possible_placement_unique;
    list_possible_placement_unique.push_back(list_possible_placement[0]);

    for (vector<int> temp:list_possible_placement){
        for (vector<int> uniquemember : list_possible_placement_unique){
            if ((temp[0]!=uniquemember[0])||(temp[1]!=uniquemember[1])){
                list_possible_placement_unique.push_back(temp);
            }
        }
    }
    return list_possible_placement_unique;
}




