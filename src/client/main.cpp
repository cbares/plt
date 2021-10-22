#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.h>

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    Mana mana;
    mana.setAmount(3);
    cout << "Le joueur possède " << mana.getAmount() << " cristaux de mana" << endl;
    mana.setAmount(10); 
    cout << "Le joueur possède " << mana.getAmount() << " cristaux de mana" << endl;
    return 0;
}
