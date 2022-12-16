#include "RandomAI.hpp"
#include "state.hpp"
#include "iostream"
#include "random"
#include <engine.hpp>

using namespace std;
using namespace state;
using namespace engine;

ai::RandomAI::RandomAI(state::Game &game) : AI(game) {
this->ai=&game;
this->player_a=true;
}

std::vector<int> ai::RandomAI::runAI() {

    vector<int> result;


    int choix_op;
    vector<int> list_choice_insect;
    int i = 0;
    int index_insect;

    cout << "Choix possibles pour l'IA\n" << endl;
    for (auto &ins: this->ai->GetAllInsects()) {

        if (ins->GetColor() == "Black") {
            cout << "I= " << i << " -->  " << ins->GetName() << "  |  " << ins->GetColor() << "  |  ["
                 << ins->Get_Position()[0] << ";" << ins->Get_Position()[1] << "] "
                 << ins->GetIsPlaced() << " \n";
            list_choice_insect.push_back(i);
        }
        i++;
    }



    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    uniform_int_distribution<> dist(0, list_choice_insect.size() -1); // distribute results between 1 and list_choice_insect.size()-1 inclusive.
    int rand=dist(gen);
    auto choice_insect = ai->GetAllInsects()[list_choice_insect[rand]];
    index_insect = list_choice_insect[rand];
    cout << "Insecte choisi : " << choice_insect->GetName() << endl;

    vector<Case> list_case;
    for (int i = 0; i < ai->GetMap()->GetLength(); i++) {
        for (int j = 0; j < ai->GetMap()->GetWidth(); j++) {
            list_case.push_back(ai->GetMap()->GetListCase()[i][j]);
        }
    }


    vector<vector<int>> temp_coord;
    if (choice_insect->GetIsPlaced() == 0) {
        choix_op=0;
        temp_coord = choice_insect->Possible_Placement_Insect(ai->GetAllInsect_placed(), list_case);
    } else {
        choix_op=1;
        temp_coord = choice_insect->Possible_Deplacement_Insect(ai->GetAllInsect_placed(),
                                                                list_case);
    }

    while (temp_coord.size() == 0) {

        random_device rd;   // non-deterministic generator
        mt19937 gen(rd());  // to seed mersenne twister.
        uniform_int_distribution<> dist(0, list_choice_insect.size() -
                                           1); // distribute results between 1 and list_choice_insect.size()-1 inclusive.

        auto choice_insect = ai->GetAllInsects()[list_choice_insect[dist(gen)]];

        cout << "INSECTE : L'IA A CHOISI : " << choice_insect->GetName() << endl;

        vector<Case> list_case;
        for (int i = 0; i < ai->GetMap()->GetLength(); i++) {
            for (int j = 0; j < ai->GetMap()->GetWidth(); j++) {
                list_case.push_back(ai->GetMap()->GetListCase()[i][j]);
            }
        }
        if (choice_insect->GetIsPlaced() == 0) {
            temp_coord = choice_insect->Possible_Placement_Insect(ai->GetAllInsect_placed(), list_case);
            choix_op = 0;
        } else {
            temp_coord = choice_insect->Possible_Deplacement_Insect(ai->GetAllInsect_placed(),list_case);
            choix_op = 1;
        }

    }

    cout << "Coordonnées possibles :\n " << endl;
    int h = 0;
    for (auto case_temp: temp_coord) {
        cout << "I= " << h << " -->  " << " [" << case_temp[0] << ";" << case_temp[1] << "]\n";
        h++;
    }

    uniform_int_distribution<> dist2(0, list_choice_insect.size() -
                                        1); // distribute results between 1 and list_choice_insect.size()-1 inclusive.
    auto choice_coord = temp_coord[dist2(gen)];

    cout << "POSITION : L'IA A CHOISI : [" << choice_coord[0] << " , " << choice_coord[1] << "]\n" << endl;

    result.push_back(choix_op);
    result.push_back(choice_coord[0]);
    result.push_back(choice_coord[1]);
    result.push_back(index_insect);



    return result;
}
