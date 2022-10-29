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

int main(int argc,char* argv[])
{

    Map maptest = Map(5,3);

    cout << "CONSTRUCTEUR OK" << endl;





    for (int i=0;i<maptest.GetLength();i++){
        for(int j=0;j<maptest.GetWidth();j++){

            int x=maptest.GetListCase()[i][j].GetPosition()[0];
            int y=maptest.GetListCase()[i][j].GetPosition()[1];

            cout << "x="<< x <<"  et y="<< y <<" et empty= "<< maptest.GetListCase()[i][j].GetEmpty() << endl;

        }
    }







    if ((string)argv[argc-1]=="hello"){
        cout << "Hello World !" << endl;
    }
else {
        cout << "It works !" << endl;
}


    return 0;
}
