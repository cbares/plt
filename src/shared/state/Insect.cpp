#include "Insect.hpp"
#include "Case.hpp"
#include <iostream>
using namespace std;

void state::Insect::Update_Coord(std::vector<int> coord) {

    this->Coord=coord;

}

std::vector<int> state::Insect::Get_Position() {
    return this->Coord;
}

std::string state::Insect::GetName() {
    return this->Name;
}

std::string state::Insect::GetColor() {
    return this->Color;
}

int state::Insect::GetLevel() {
    return this->Level;
}

void state::Insect::SetPosition(std::vector<int> coord) {
    this->Coord=coord;
}

void state::Insect::SetLevel(int level) {   this->Level=level;
}

bool state::Insect::GetIsPlaced() {
    return this->IsPlaced;
}

void state::Insect::SetIsPlaced(bool state) {
    this->IsPlaced=state;
}



std::vector<std::vector<int>> state::Insect::Possible_Placement_Insect(vector<Insect> list_insect_placed,vector<Case> list_case) {

    std::vector<std::vector<int>> list_possible_placement;
    vector<Insect> Allies_Insect;



    // Si aucun insecte est posé
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


    //Si aucun insecte allié est posé

    if (Allies_Insect.size()==0){
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
                else if ((casetemp.GetPosition()[0]==i-1)&&(casetemp.GetPosition()[1]==j-1)&&(casetemp.GetEmpty()== true)){
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
            else if ((casetemp.GetPosition()[0]==i-1)&&(casetemp.GetPosition()[1]==j-1)&&(casetemp.GetEmpty()== true)){
                list_possible_placement.push_back(casetemp.GetPosition());
            }
        }

    }

//RECHERCHE DES DOUBLONS DANS LA LISTES DES COORDONNEES POSSIBLES
    //vector<vector<int>> list_possible_placement_unique;
    //list_possible_placement_unique.push_back(list_possible_placement[0]);



    for (int i=0;i<list_possible_placement.size();i++){
        cout << "Coord dispos :"<<list_possible_placement[i][0]<<" "<<list_possible_placement[i][1] << endl;
    }


   /* for (vector<int> uniquemember: list_possible_placement_unique) {

        cout << "new loop" << endl;

        for (int i = 0; i < list_possible_placement_unique.size(); i++) {
            cout << "Etat d'unique :" << list_possible_placement_unique[i][0] << " "
                 << list_possible_placement_unique[i][1] << endl;
        }

        for (vector<int> temp: list_possible_placement) {
            cout << "temp = " << temp[0] << temp[1] << endl;
            cout << "candidat1 = " << uniquemember[0] << uniquemember[1] << endl;

            if ((temp[0] != uniquemember[0]) || (temp[1] != uniquemember[1])) {
                cout << "IF OK" << endl;
                list_possible_placement_unique.push_back(temp);
                cout << "ajout de = " << temp[0] << temp[1] << endl;
            }
        }
    }*/


   vector<int> indicetosup;
    vector<vector<int>> list_possible_placement_unique=list_possible_placement;
    for (int i=0;i<list_possible_placement.size()-1;i++){
        for (int j=i+1;j<list_possible_placement.size();j++){
            auto temp = list_possible_placement[i];
            auto candidat = list_possible_placement[j];
            if ((temp[0] == candidat[0]) && (temp[1] == candidat[1])){
                indicetosup.push_back(j);
            }

        }

    }
    for (int i=0;i<indicetosup.size();i++){
        list_possible_placement_unique.erase(list_possible_placement_unique.begin()+indicetosup[i]-i);
    }



    cout <<"OK FINAL"<< endl;
    return list_possible_placement_unique;
}

std::vector<std::vector<int>>
state::Insect::Possible_Deplacement_Insect(vector<Insect> list_insect_placed, vector<Case> list_case) {
    return std::vector<std::vector<int>>();
}

state::Insect::Insect(std::string name, std::string color, std::vector<int> coord, int level) {
    this->Name=name;this->Color=color;this->Coord=coord;this->Level=level;this->IsPlaced=false;

}










