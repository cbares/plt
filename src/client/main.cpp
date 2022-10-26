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
    Case case1=Case({1,2},false);
    case1.GetEmpty();
    list<int> coord=case1.GetPosition();


    for(list<int>::iterator it = coord.begin(); it != coord.end(); it++){
        cout << *it << endl;
    }

    if ((string)argv[argc-1]=="hello"){
        cout << "Hello World !" << endl;
    }
else {
        cout << "It works !" << endl;
}


    return 0;
}
