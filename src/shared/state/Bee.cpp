#include "Bee.hpp"
#include "vector"
#include <iostream>
#include <algorithm>
using namespace std;

state::Bee::Bee(std::string name, std::string color, std::vector<int> coord, int level) : Insect(name, color, coord,level) {
    Insect(this->Name = name, this->Color = color, this->Coord = coord, this->Level= level );
}

std::vector<std::vector<int>>
state::Bee::Possible_Deplacement_Insect(vector<Insect> list_insect_placed, vector<Case> list_case) {

    vector<int> coord = this->Coord;
    int i_depart = coord[0];
    int j_depart = coord[1];

    std::vector<std::vector<int>> list_possible_placement;

        //Parité de la colonne
    if (j_depart%2==0){


    for (Case casetemp:list_case){

            if((casetemp.GetPosition()[0]==i_depart)&&(casetemp.GetPosition()[1]==j_depart-1)&&(casetemp.GetEmpty()== true)) {

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];


                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }


            }
            else if((casetemp.GetPosition()[0]==i_depart)&&(casetemp.GetPosition()[1]==j_depart+1)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];


                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
            else if ((casetemp.GetPosition()[0]==i_depart-1)&&(casetemp.GetPosition()[1]==j_depart)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];

                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
            else if ((casetemp.GetPosition()[0]==i_depart+1)&&(casetemp.GetPosition()[1]==j_depart-1)&&(casetemp.GetEmpty()== true)){
                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];

                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
            else if ((casetemp.GetPosition()[0]==i_depart+1)&&(casetemp.GetPosition()[1]==j_depart)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];

                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
            else if ((casetemp.GetPosition()[0]==i_depart+1)&&(casetemp.GetPosition()[1]==j_depart+1)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];

                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
        }
    }
    else{

        for (Case casetemp:list_case){

            if((casetemp.GetPosition()[0]==i_depart-1)&&(casetemp.GetPosition()[1]==j_depart-1)&&(casetemp.GetEmpty()== true)) {

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];


                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }


            }
            else if((casetemp.GetPosition()[0]==i_depart-1)&&(casetemp.GetPosition()[1]==j_depart)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];


                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
            else if ((casetemp.GetPosition()[0]==i_depart-1)&&(casetemp.GetPosition()[1]==j_depart+1)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];

                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
            else if ((casetemp.GetPosition()[0]==i_depart)&&(casetemp.GetPosition()[1]==j_depart-1)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];

                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
            else if ((casetemp.GetPosition()[0]==i_depart)&&(casetemp.GetPosition()[1]==j_depart+1)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];

                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
            else if ((casetemp.GetPosition()[0]==i_depart+1)&&(casetemp.GetPosition()[1]==j_depart)&&(casetemp.GetEmpty()== true)){

                int x = casetemp.GetPosition()[0];
                int y = casetemp.GetPosition()[1];

                if (y%2==0){
                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1)&& ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
                else{

                    for (Case casetemp2: list_case) {
                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&(casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0]!=i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                            list_possible_placement.push_back(casetemp.GetPosition());
                        }
                    }
                }
            }
        }
    }

//RECHERCHE DES DOUBLONS DANS LA LISTES DES COORDONNEES POSSIBLES
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
    std::sort(indicetosup.begin(), indicetosup.end());
    std::unique(indicetosup.begin(), indicetosup.end());
    for (int i=0;i<indicetosup.size();i++){
        list_possible_placement_unique.erase(list_possible_placement_unique.begin()+indicetosup[i]-i);
    }


    return list_possible_placement_unique;
}

