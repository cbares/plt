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
    Exemple exemple;
    exemple.setX(53);
    
    cout << "Slt ";
    
	for(int i=1; i<argc; i++)
	{
		 cout << argv[i] << " ";
	}
	
	cout << endl;
	
	
    return 0;
}
