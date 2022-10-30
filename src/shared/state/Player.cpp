//
// Created by ensea on 28/10/22.
//

#include <iostream>
#include "Player.hpp"


using namespace std;
using namespace state;

Player::Player(string name, string color) {
    Name = name;
    Color = color;
}

string Player::GetName() {
    return Name;
}

string Player::GetColor() {
    return Color;
}

void Player::Add_Insect(Insect insecte, vector<Insect>& list) {
    return list.push_back(insecte);
}

void Player::Remove_Insect(Insect insecte, vector<Insect>& list) {
    //bool stInsect = 0;
    for (int i=0; i<list.size(); i++) {
        if (list[i].GetName() == insecte.GetName()) {
            list.erase(list.begin() + i);
            //stInsect = 1;
        }
        /*if (stInsect) {
            stInsect = 0;
            break;
        }*/
    }
}

std::vector<Insect> Player::Get_List_Insect_Remaining() {
    return this->ListInsectRemaining;
}

std::vector<Insect> Player::Get_List_Insect_Played() {
    return this->ListInsectPlayed;
}


