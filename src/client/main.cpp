#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.hpp>
using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
//Créer la map
    Map maptest = Map(10,12);

//On crée les insectes
    Bee testbee = Bee("test","White",{2,1},0);
    Bee testbee2 = Bee("test2","White",{1,1},0);
    Bee testbee3 = Bee("test3","White",{1,2},0);

    //On met les cases utilisées à empty=false (en gros on place les instectes dans la map)
    for (int i=0;i<maptest.GetLength();i++){
        for(int j=0;j<maptest.GetWidth();j++){
            if((maptest.GetListCase()[i][j].GetPosition()[0]==1)&&(maptest.GetListCase()[i][j].GetPosition()[1]==1)){
                maptest.SetListCase(Case({i,j},false),i,j);
            }
           if((maptest.GetListCase()[i][j].GetPosition()[0]==1)&&(maptest.GetListCase()[i][j].GetPosition()[1]==2)){
                maptest.SetListCase(Case({i,j},false),i,j);
            }

            if((maptest.GetListCase()[i][j].GetPosition()[0]==2)&&(maptest.GetListCase()[i][j].GetPosition()[1]==1)){
                maptest.SetListCase(Case({i,j},false),i,j);
            }

            /*if((maptest.GetListCase()[i][j].GetPosition()[0]==1)&&(maptest.GetListCase()[i][j].GetPosition()[1]==2)){
                maptest.SetListCase(Case({i,j},false),i,j);
            }*/
        }
    }

    //On vérifie l'état des cases occupées
    /*for (int i=0;i<maptest.GetLength();i++){
        for(int j=0;j<maptest.GetWidth();j++){
            if((maptest.GetListCase()[i][j].GetPosition()[0]==0)&&(maptest.GetListCase()[i][j].GetPosition()[1]==1)){
                cout <<"Pour x=" << i <<" et pour y="<<j<<" on a l'état : "<< maptest.GetListCase()[i][j].GetEmpty() << endl;
            }
            if((maptest.GetListCase()[i][j].GetPosition()[0]==2)&&(maptest.GetListCase()[i][j].GetPosition()[1]==1)){
                cout <<"Pour x=" << i <<" et pour y="<<j<<" on a l'état : "<< maptest.GetListCase()[i][j].GetEmpty() << endl;
            }
            if((maptest.GetListCase()[i][j].GetPosition()[0]==1)&&(maptest.GetListCase()[i][j].GetPosition()[1]==1)){
                cout <<"Pour x=" << i <<" et pour y="<<j<<" on a l'état : "<< maptest.GetListCase()[i][j].GetEmpty() << endl;
            }
            if((maptest.GetListCase()[i][j].GetPosition()[0]==3)&&(maptest.GetListCase()[i][j].GetPosition()[1]==2)){
                cout <<"Pour x=" << i <<" et pour y="<<j<<" on a l'état : "<< maptest.GetListCase()[i][j].GetEmpty() << endl;
            }
        }
    }*/


    vector<Insect> listins;
    listins.push_back(testbee);
    listins.push_back(testbee2);
    listins.push_back(testbee3);


    //Copie de maptest.GetListCase() pour en faire une liste de Case qui peut être e argument de Possible_Placement_Insect
    vector<Case> listcasetemp;

    for (int i=0;i<maptest.GetLength();i++){
        for(int j=0;j<maptest.GetWidth();j++){
            listcasetemp.push_back(maptest.GetListCase()[i][j]);
        }
    }



    //vector<vector<int>> coordpossibles=testbee.Possible_Placement_Insect(listins,listcasetemp);
    vector<vector<int>> coordpossibles=testbee.Possible_Deplacement_Insect(listins,listcasetemp);


for (int i=0;i<coordpossibles.size();i++){
    cout << "Coord dispos uniques :"<<coordpossibles[i][0]<<" "<<coordpossibles[i][1] << endl;
}

    if ((string)argv[argc-1]=="hello"){
        cout << "Hello World !" << endl;
    }
else {
        cout << "It works !" << endl;}


    return 0;
}
