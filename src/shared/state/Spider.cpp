#include "Spider.hpp"
#include "vector"
#include <iostream>
using namespace std;


state::Spider::Spider(std::string name, std::string color, std::vector<int> coord, int level) : Insect(name, color,
                                                                                                       coord, level) {
    Insect(this->Name = name, this->Color = color, this->Coord = coord, this->Level= level );
}

std::vector<std::vector<int>>
state::Spider::Possible_Deplacement_Insect(vector<Insect> list_insect_placed, vector<Case> list_case) {

    vector<int> coord = this->Coord;
    int i_depart = coord[0];
    int j_depart = coord[1];

    std::vector<std::vector<int>> list_possible_placement;




    //DEBUT
    for (Case case_premier:list_case){ //On vérifie les premières cases dispos



        //***************************************************1.1*****I-1 ; J  *************************************************************************//

        if((case_premier.GetPosition()[0]==i_depart-1)&&(case_premier.GetPosition()[1]==j_depart)&&(case_premier.GetEmpty()== true)) {
            int x = case_premier.GetPosition()[0];
            int y = case_premier.GetPosition()[1];

            std::vector<std::vector<int>> list_premiere_case;


              //*************************************************PRESENCE DE VOISINS**********************************************//
            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {

                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                }
            }

            //******************************************PASSAGE A LA DEUXIEME CASE**********************//
            if (list_premiere_case.size()!=0){

                vector<int> premiere_case=list_premiere_case[0];
                int i_case1=premiere_case[0];int j_case1 = premiere_case[1];






                for (Case case_deuxieme:list_case) { //On vérifie les deuxièmes cases dispos

                    //*****************************************2.1********** I-1;J**********************************************//
                    if ((case_deuxieme.GetPosition()[0] == i_case1 - 1) && (case_deuxieme.GetPosition()[1] == j_case1) &&
                        (case_deuxieme.GetPosition()[0] != i_depart) &&
                        (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                    //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                            (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) &&
                                            (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false))
                                            ||
                                            ((casetemp2.GetPosition()[0] == x - 1) &&
                                            (casetemp2.GetPosition()[1] == y + 1) &&
                                            (casetemp2.GetPosition()[0] != i_depart) &&
                                            (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false))
                                            ||
                                            ((casetemp2.GetPosition()[0] == x) &&
                                            (casetemp2.GetPosition()[1] == y - 1) &&
                                            (casetemp2.GetPosition()[0] != i_depart) &&
                                            (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false))
                                            ||
                                            ((casetemp2.GetPosition()[0] == x) &&
                                            (casetemp2.GetPosition()[1] == y + 1) &&
                                            (casetemp2.GetPosition()[0] != i_depart) &&
                                            (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false))
                                            ||
                                            ((casetemp2.GetPosition()[0] == x + 1) &&
                                            (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) &&
                                            (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false))
                                            ||
                                            ((casetemp2.GetPosition()[0] == x - 1) &&
                                            (casetemp2.GetPosition()[1] == y - 1) &&
                                            (casetemp2.GetPosition()[0] != i_depart) &&
                                            (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //***********************************************FIN 2.1****************************************************//


                    //*****************************************2.2********** I-1;J+1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 - 1) && (case_deuxieme.GetPosition()[1] == j_case1+1) &&
                        (case_deuxieme.GetPosition()[0] != i_depart) &&
                        (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//
                                else if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//
                                else if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //***********************************************FIN 2.2****************************************************//


                    //*****************************************2.3********** I;J-1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                        (case_deuxieme.GetPosition()[0] != i_depart) &&
                        (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //***********************************************FIN 2.3****************************************************//


                    //*****************************************2.4********** I;J+1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1+1) &&
                        (case_deuxieme.GetPosition()[0] != i_depart) &&
                        (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //***********************************************FIN 2.4****************************************************//

                    //*****************************************2.5********** I+1;J**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                        (case_deuxieme.GetPosition()[0] != i_depart) &&
                        (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //***********************************************FIN 2.5****************************************************//

                    //*****************************************2.6********** I-1;J-1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1-1) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                        (case_deuxieme.GetPosition()[0] != i_depart) &&
                        (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //***********************************************FIN 2.6****************************************************//

                }
            }
        }

        //***************************************************FIN 1.1 **********************************************************************************//

        //***************************************************1.2*****I-1 ; J+1  *************************************************************************//

        else if((case_premier.GetPosition()[0]==i_depart-1)&&(case_premier.GetPosition()[1]==j_depart+1)&&(case_premier.GetEmpty()== true)) {
            int x = case_premier.GetPosition()[0];
            int y = case_premier.GetPosition()[1];

            std::vector<std::vector<int>> list_premiere_case;


            //*************************************************PRESENCE DE VOISINS**********************************************//
            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {

                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                }
            }

            //******************************************PASSAGE A LA DEUXIEME CASE**********************//
            if (list_premiere_case.size()!=0){

                vector<int> premiere_case=list_premiere_case[0];
                int i_case1=premiere_case[0];int j_case1 = premiere_case[1];






                for (Case case_deuxieme:list_case) { //On vérifie les deuxièmes cases dispos

                    //*****************************************2.1********** I-1;J**********************************************//
                    if ((case_deuxieme.GetPosition()[0] == i_case1 - 1) && (case_deuxieme.GetPosition()[1] == j_case1) &&
                        (case_deuxieme.GetPosition()[0] != i_depart) &&
                        (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.1****************************************************//


                        //*****************************************2.2********** I-1;J+1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 - 1) && (case_deuxieme.GetPosition()[1] == j_case1+1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                    //*****************************************3.2********** I-1;J+1**********************************************//
                                else if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                         (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                         (case_troisieme.GetPosition()[0] != i_depart) &&
                                         (case_troisieme.GetPosition()[1] != j_depart) &&
                                         (case_troisieme.GetPosition()[0] != i_case1) &&
                                         (case_troisieme.GetPosition()[1] != j_case1) &&
                                         (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                    //*****************************************3.3********** I;J-1**********************************************//
                                else if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                         (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                         (case_troisieme.GetPosition()[0] != i_depart) &&
                                         (case_troisieme.GetPosition()[1] != j_depart) &&
                                         (case_troisieme.GetPosition()[0] != i_case1) &&
                                         (case_troisieme.GetPosition()[1] != j_case1) &&
                                         (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.2****************************************************//


                        //*****************************************2.3********** I;J-1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.3****************************************************//


                        //*****************************************2.4********** I;J+1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1+1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.4****************************************************//

                        //*****************************************2.5********** I+1;J**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.5****************************************************//

                        //*****************************************2.6********** I-1;J-1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1-1) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //***********************************************FIN 2.6****************************************************//

                }
            }
        }

        //***************************************************FIN 1.2 **********************************************************************************//

            //***************************************************1.3*****I-1 ; J+1  *************************************************************************//

        else if((case_premier.GetPosition()[0]==i_depart-1)&&(case_premier.GetPosition()[1]==j_depart+1)&&(case_premier.GetEmpty()== true)) {
            int x = case_premier.GetPosition()[0];
            int y = case_premier.GetPosition()[1];

            std::vector<std::vector<int>> list_premiere_case;


            //*************************************************PRESENCE DE VOISINS**********************************************//
            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {

                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) && (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart)&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                }
            }

            //******************************************PASSAGE A LA DEUXIEME CASE**********************//
            if (list_premiere_case.size()!=0){

                vector<int> premiere_case=list_premiere_case[0];
                int i_case1=premiere_case[0];int j_case1 = premiere_case[1];






                for (Case case_deuxieme:list_case) { //On vérifie les deuxièmes cases dispos

                    //*****************************************2.1********** I-1;J**********************************************//
                    if ((case_deuxieme.GetPosition()[0] == i_case1 - 1) && (case_deuxieme.GetPosition()[1] == j_case1) &&
                        (case_deuxieme.GetPosition()[0] != i_depart) &&
                        (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.1****************************************************//


                        //*****************************************2.2********** I-1;J+1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 - 1) && (case_deuxieme.GetPosition()[1] == j_case1+1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                    //*****************************************3.2********** I-1;J+1**********************************************//
                                else if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                         (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                         (case_troisieme.GetPosition()[0] != i_depart) &&
                                         (case_troisieme.GetPosition()[1] != j_depart) &&
                                         (case_troisieme.GetPosition()[0] != i_case1) &&
                                         (case_troisieme.GetPosition()[1] != j_case1) &&
                                         (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                    //*****************************************3.3********** I;J-1**********************************************//
                                else if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                         (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                         (case_troisieme.GetPosition()[0] != i_depart) &&
                                         (case_troisieme.GetPosition()[1] != j_depart) &&
                                         (case_troisieme.GetPosition()[0] != i_case1) &&
                                         (case_troisieme.GetPosition()[1] != j_case1) &&
                                         (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.2****************************************************//


                        //*****************************************2.3********** I;J-1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.3****************************************************//


                        //*****************************************2.4********** I;J+1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1+1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.4****************************************************//

                        //*****************************************2.5********** I+1;J**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1 ) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //***********************************************FIN 2.5****************************************************//

                        //*****************************************2.6********** I-1;J-1**********************************************//
                    else if ((case_deuxieme.GetPosition()[0] == i_case1-1) && (case_deuxieme.GetPosition()[1] == j_case1-1) &&
                             (case_deuxieme.GetPosition()[0] != i_depart) &&
                             (case_deuxieme.GetPosition()[1] != j_depart)&& (case_deuxieme.GetEmpty() == true)) {
                        int x = case_deuxieme.GetPosition()[0];
                        int y = case_deuxieme.GetPosition()[1];

                        std::vector<std::vector<int>> list_deuxieme_case;

                        //*************************************************PRESENCE DE VOISINS**********************************************//
                        for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                            if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                (casetemp2.GetEmpty() == false)) {

                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                       (casetemp2.GetPosition()[0] != i_depart) &&
                                       (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                            }
                        }


                        //******************************************PASSAGE A LA TROISIEME CASE**********************//
                        if (list_deuxieme_case.size()!=0) {

                            vector<int> deuxieme_case = list_deuxieme_case[0];
                            int i_case2 = deuxieme_case[0];
                            int j_case2 = deuxieme_case[1];



                            for (Case case_troisieme:list_case) { //On vérifie les troisiemes cases dispos

                                //*****************************************3.1********** I-1;J**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {

                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.2********** I-1;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }


                                //*****************************************3.3********** I;J-1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.4********** I;J+1**********************************************//



                                if ((case_troisieme.GetPosition()[0] == i_case2 ) &&
                                    (case_troisieme.GetPosition()[1] == j_case2+1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }

                                //*****************************************3.5********** I+1;J**********************************************//


                                if ((case_troisieme.GetPosition()[0] == i_case2 + 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ( ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x) &&
                                              (casetemp2.GetPosition()[1] == y + 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x + 1) &&
                                              (casetemp2.GetPosition()[1] == y) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false))
                                             ||
                                             ((casetemp2.GetPosition()[0] == x - 1) &&
                                              (casetemp2.GetPosition()[1] == y - 1) &&
                                              (casetemp2.GetPosition()[0] != i_depart) &&
                                              (casetemp2.GetPosition()[1] != j_depart) &&
                                              (casetemp2.GetEmpty() == false)))
                                        {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }

                                    }
                                }

                                //*****************************************3.6********** I-1;J-1**********************************************//

                                if ((case_troisieme.GetPosition()[0] == i_case2 - 1) &&
                                    (case_troisieme.GetPosition()[1] == j_case2-1) &&
                                    (case_troisieme.GetPosition()[0] != i_depart) &&
                                    (case_troisieme.GetPosition()[1] != j_depart) &&
                                    (case_troisieme.GetPosition()[0] != i_case1) &&
                                    (case_troisieme.GetPosition()[1] != j_case1) &&
                                    (case_troisieme.GetEmpty() == true)) {
                                    int x = case_troisieme.GetPosition()[0];
                                    int y = case_troisieme.GetPosition()[1];
                                    //*************************************************PRESENCE DE VOISINS**********************************************//
                                    for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                                        if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                                            (casetemp2.GetPosition()[0] != i_depart) && (casetemp2.GetPosition()[1] != j_depart) &&
                                            (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                                                   (casetemp2.GetPosition()[0] != i_depart) &&
                                                   (casetemp2.GetPosition()[1] != j_depart) && (casetemp2.GetEmpty() == false)) {
                                            list_possible_placement.push_back(case_troisieme.GetPosition());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //***********************************************FIN 2.6****************************************************//

                }
            }
        }

        //***************************************************FIN 1.3 **********************************************************************************//

    }




    return Insect::Possible_Deplacement_Insect(list_insect_placed, list_case);
}





