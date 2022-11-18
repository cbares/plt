#include "Beetle.hpp"
#include "vector"
#include <iostream>
#include <algorithm>
using namespace std;


state::Beetle::Beetle(std::string name, std::string color, std::vector<int> coord, int level) : Insect(name, color,
                                                                                                       coord, level) {
    Insect(this->Name = name, this->Color = color, this->Coord = coord, this->Level= level );
}

std::vector<std::vector<int>> state::Beetle::Possible_Deplacement_Insect(vector<Insect> list_insect_placed, vector<Case> list_case) {
    vector<int> coord = this->Coord;
    int i_depart = coord[0];
    int j_depart = coord[1];

    std::vector<std::vector<int>> list_possible_placement;


    if (j_depart%2==0){
        //DEBUT
        for (Case case_premier:list_case) { //On vérifie les premières cases dispos
            std::vector<std::vector<int>> res;
            //*****************************************1.1********** I;J-1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart) && (case_premier.GetPosition()[1] == j_depart-1)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }

            //***********************************************FIN 1.1****************************************************//

            //*****************************************1.2********** I;J+1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart) && (case_premier.GetPosition()[1] == j_depart+1)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.2****************************************************//

            //*****************************************1.3********** I-1;J**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart-1) && (case_premier.GetPosition()[1] == j_depart)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.3****************************************************//

            //*****************************************1.4********** I+1;J-1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart+1) && (case_premier.GetPosition()[1] == j_depart-1)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.4****************************************************//

            //*****************************************1.5********** I+1;J**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart+1) && (case_premier.GetPosition()[1] == j_depart)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.5****************************************************//

            //*****************************************1.6********** I+1;J+1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart+1) && (case_premier.GetPosition()[1] == j_depart+1)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.6****************************************************//
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
        }
    }
    else{
        for (Case case_premier:list_case) { //On vérifie les premières cases dispos
            std::vector<std::vector<int>> res;
            //*****************************************1.1********** I-1;J-1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart-1) && (case_premier.GetPosition()[1] == j_depart-1)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.1****************************************************//

            //*****************************************1.2********** I-1;J**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart-1) && (case_premier.GetPosition()[1] == j_depart)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.2****************************************************//

            //*****************************************1.3********** I-1;J+1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart-1) && (case_premier.GetPosition()[1] == j_depart+1)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.3****************************************************//

            //*****************************************1.4********** I;J-1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart) && (case_premier.GetPosition()[1] == j_depart-1)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.4****************************************************//

            //*****************************************1.5********** I;J+1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart) && (case_premier.GetPosition()[1] == j_depart+1)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.5****************************************************//

            //*****************************************1.6********** I+1;J**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart+1) && (case_premier.GetPosition()[1] == j_depart)) {
                int i_case1 = case_premier.GetPosition()[0];
                int j_case1 = case_premier.GetPosition()[1];

                if (case_premier.GetEmpty()==true){
                    //Cas où la case est vide
                    if (j_case1 % 2 == 0) {
                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                    else {
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 - 1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 - 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1) && (casetemp2.GetPosition()[1] == j_case1 + 1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == i_case1 + 1) && (casetemp2.GetPosition()[1] == j_case1) &&
                                       ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                                       (casetemp2.GetEmpty() == false)) {
                                res.push_back(case_premier.GetPosition());
                            }
                        }
                    }
                }
                else {
                    //Cas où la case est occupée
                    res.push_back(case_premier.GetPosition());
                }

            }
            //***********************************************FIN 1.6****************************************************//
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
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