#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.hpp>
#include <list>
using namespace std;
using namespace state;

int main(int argc,char* argv[]){

    Bee benzema = Bee("Benzema", "White", {-1,-1},0);
    Player naruto = Player("naruto","blanc");
    naruto.Add_Insect_Remaining(benzema);
    cout << "Voici la liste des pions restants de naruto : " << endl;
    for (Insect i: naruto.Get_List_Insect_Remaining())
        cout << i.GetColor() << ' ';

if ((string)argv[argc-1]=="hello"){
        cout << "Hello World !" << endl;
    }
else {
        cout << "It works !" << endl;
}
    return 0;
}


/*
Map maptest = Map(5,3);

cout << "CONSTRUCTEUR OK" << endl;

for (int i=0;i<maptest.GetLength();i++){
    for(int j=0;j<maptest.GetWidth();j++){

        int x=maptest.GetListCase()[i][j].GetPosition()[0];
        int y=maptest.GetListCase()[i][j].GetPosition()[1];

        cout << "x="<< x <<"  et y="<< y <<" et empty= "<< maptest.GetListCase()[i][j].GetEmpty() << endl;

    }
}
*/

/*
//declaration d'objet de la classe
Insect moucheA1 = Insect("Mouche_A1", "blanc", {-1,-1},0);
Insect moucheA2 = Insect("Mouche_A2", "blanc", {-1,-1},0);
Insect abeilleA = Insect("Abeille_A", "blanc", {-1,-1},0);
Insect moucheB1 = Insect("Mouche_B1", "noir", {-1,-1},0);
Insect moucheB2 = Insect("Mouche_B2", "noir", {-1,-1},0);
Insect abeilleB = Insect("Abeille_B", "noir", {-1,-1},0);


//déclaration joueur
Player naruto = Player("naruto","blanc");
Player sasuke = Player("sasuke","blanc");

//ajout des insectes à la liste

naruto.Add_Insect_Remaining(moucheA1);
naruto.Add_Insect_Remaining(moucheA2);
naruto.Add_Insect_Remaining(abeilleA);
sasuke.Add_Insect_Remaining(moucheB1);
sasuke.Add_Insect_Remaining(moucheB2);
sasuke.Add_Insect_Remaining(abeilleB);

sasuke.Add_Insect_Played(moucheB1);

cout << "Voici la liste des pions restants de naruto : " << endl;
for (Insect i: naruto.Get_List_Insect_Remaining())
   cout << i.GetName() << ' ';

cout << "\nVoici la liste des pions restants de sasuke : " << endl;
for (Insect i: sasuke.Get_List_Insect_Remaining())
    cout << i.GetName() << ' ';

cout << "\nVoici la liste des pions joués de sasuke : " << endl;
for (Insect i: sasuke.Get_List_Insect_Played())
    cout << i.GetName() << ' ';
*/