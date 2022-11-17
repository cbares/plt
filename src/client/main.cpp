#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.hpp>
#include <list>
#include <sstream>
#include <render.hpp>
#include <unordered_map>

using namespace std;
using namespace state;
using namespace render;

int main(int argc,char* argv[]){

    if ((string)argv[argc-1]=="hello"){
        cout << "Hello World !" << endl;
    }
    else if ((string)argv[argc-1]=="render"){
        sf::RenderWindow window(sf::VideoMode(1080, 720), "HIVE",sf::Style::Close | sf::Style::Titlebar);
        Game state = Game();

        Scene scene = Scene(state);

        Player Benzema = Player("Benzema","White");
        Player Giroud =  Player("Giroud", "Black");

        std::vector<Insect*> temp;
        std::vector<Insect*> temp2;
        Bee Bee_B = Bee("Bee_B", "White", {7,5},0);temp2.push_back(&Bee_B);
        Bee Bee_A = Bee("Bee_A", "Black", {6,5},0); temp.push_back(&Bee_A);
        Bee Ant_B = Bee("Ant_B1", "White", {7,4},0);temp2.push_back(&Ant_B);
        Bee Ant_A = Bee("Ant_A1", "Black", {6,6},0);temp.push_back(&Ant_A);
        Bee Grasshopper_B = Bee("Grasshopper_B1", "White", {6,3},0);temp2.push_back(&Grasshopper_B);
        Bee Grasshopper_A = Bee("Grasshopper_A1", "Black", {6,7},0);temp.push_back(&Grasshopper_A);
        Bee Spider_B = Bee("Spider_B1", "White", {7,3},0);temp2.push_back(&Spider_B);
        Bee Spider_A = Bee("Spider_A1", "Black", {5,7},0);temp.push_back(&Spider_A);

        std::vector<Insect*> temp3;
        std::vector<Insect*> temp4;

        Bee Ant_B2 = Bee("Ant_B2", "White", {7,4},0);temp4.push_back(&Ant_B);
        Bee Ant_A2 = Bee("Ant_A2", "Black", {6,6},0);temp3.push_back(&Ant_A);
        Bee Grasshopper_B2 = Bee("Grasshopper_B2", "White", {6,3},0);temp4.push_back(&Grasshopper_B);
        Bee Grasshopper_A2 = Bee("Grasshopper_A2", "Black", {6,7},0);temp3.push_back(&Grasshopper_A);
        Bee Spider_B2 = Bee("Spider_B2", "White", {7,3},0);temp4.push_back(&Spider_B);
        Bee Spider_A2 = Bee("Spider_A2", "Black", {5,7},0);temp3.push_back(&Spider_A);


        for(auto &i : temp){
            Giroud.Add_Insect_Played(*i);
        }
        for(auto &j : temp2){
            Benzema.Add_Insect_Played(*j);
        }
        for(auto &i : temp3){
            Giroud.Add_Insect_Remaining(*i);
        }
        for(auto &j : temp4){
            Benzema.Add_Insect_Remaining(*j);
        }
        state.AppendListJoueur(Giroud);
        state.AppendListJoueur(Benzema);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            scene.drawScene(state, window);
            //window.draw(insectHextest["Bee_A"]);
            window.display();
        }
    }
    else {
        cout << "It works !" << endl;
    }

    return 0;
}
/*MapDraw mapdraw = MapDraw();
   InsectDraw insectdraw = InsectDraw(mapdraw.mapPixelPosition,mapdraw.mapPixelRemainingPosition);
   //cout << mapdraw.mapPixelPosition[5][4].x << endl;

   sf::CircleShape temphexa(24, 6);
   temphexa.rotate(90);
   temphexa.setOrigin({ temphexa.getRadius(), temphexa.getRadius() });

   std::vector<std::vector<sf::Vector2f>> maptest;

   for (int y = 0; y < 17 ; ++y) {
       std::vector<sf::Vector2f> temp;
       for (int x = 0; x < 10; ++x) {
           temphexa.setPosition(200 + y * 40.f , (y % 2 ? 50 : 75) + x * 50.f + 50);
           temp.push_back(temphexa.getPosition());
       }
       maptest.push_back(temp);
   }
   cout << maptest[5][4].x << endl;*/

/*
   sf::RenderWindow window(sf::VideoMode(1080, 720), "HIVE",sf::Style::Close | sf::Style::Titlebar);

   sf::Texture texture; //Background
   if (!texture.loadFromFile("/media/sf_dossier_partage/ressources/backgroundqs.jpg"))
       return EXIT_FAILURE;
   sf::Sprite sprite(texture);
   sf::Font font; //Police écriture
   if (!font.loadFromFile("/home/ensea/CLionProjects/plt/res/arial.ttf"))
       return EXIT_FAILURE;
   sf::Text text("Hello SFML", font, 20);
   text.setPosition(1000,600);


   sf::Color ruche = sf::Color(255,130,65,255);
   sf::CircleShape hexagon(24, 6);
   hexagon.setOutlineColor(sf::Color::White);
   hexagon.setOutlineThickness(2);
   hexagon.setFillColor(ruche);
   hexagon.rotate(90);
   hexagon.setOrigin({ hexagon.getRadius(), hexagon.getRadius() });


   std::vector<sf::Vector2f> map;
   std::vector<std::vector<sf::Vector2f>> mappixel;

   for (int y = 0; y < 17 ; ++y) {
       vector<sf::Vector2f> temp;
       for (int x = 0; x < 10; ++x) {

           hexagon.setPosition(200 + y * 40.f , (y % 2 ? 50 : 75) + x * 50.f + 50);
           temp.push_back(hexagon.getPosition());
           window.draw(hexagon);
       }
       mappixel.push_back(temp);
   }

   Bee benzema = Bee("Benzema", "Black", {10,5},0);
   sf::Texture abeille;
   if (!abeille.loadFromFile("/home/ensea/CLionProjects/plt/res/pion/ant_w.png"))
       return EXIT_FAILURE;

   sf::CircleShape abeille_hexagon(24, 6);
   abeille_hexagon.setOutlineThickness(2);
   abeille_hexagon.setOutlineColor(sf::Color:: Black);
   abeille_hexagon.setFillColor(sf::Color::White);
   abeille_hexagon.setOrigin({ abeille_hexagon.getRadius(), abeille_hexagon.getRadius() });
   abeille_hexagon.setPosition(mappixel[benzema.Get_Position()[0]][benzema.Get_Position()[1]].x,mappixel[benzema.Get_Position()[0]][benzema.Get_Position()[1]].y);
   abeille_hexagon.rotate(90);

   abeille_hexagon.setTexture(&abeille);
    std::map<string,sf::CircleShape> antshape;
    antshape["Ant_A1"] = abeille_hexagon;
   cout<< benzema.Get_Position()[0] << benzema.Get_Position()[1] <<endl;
   cout << mappixel[6][7].x << endl;

   while (window.isOpen())
   {
       int xmouse = sf::Mouse::getPosition(window).x;
       int ymouse = sf::Mouse::getPosition(window).y;

       std::stringstream ss;
       ss << "X" << xmouse <<"\n"
          << "Y" << ymouse << "\n";

       text.setString(ss.str());

       sf::Event event;
       while (window.pollEvent(event))
       {
           // Close window: exit
           if (event.type == sf::Event::Closed)
               window.close();
       }

       window.clear();

       window.draw(sprite);

       window.draw(text);

       //window.draw(testsprite);


       for (int y = 0; y < 17 ; ++y) {
           for (int x = 0; x < 10; ++x) {

               hexagon.setPosition(200 + y * 40.f , (y % 2 ? 50 : 75) + x * 50.f + 50);
               //map.push_back(hexagon.getPosition());
               window.draw(hexagon);
           }
       }

       for (int y = 0; y < 13 ; ++y) {
           for (int x = 0; x < 1; ++x) {

               hexagon.setPosition(279 + y * 40.f , (y % 2 ? 50 : 75) + x * 50.f + 600);
               //map.push_back(hexagon.getPosition());
               window.draw(hexagon);
           }
       }

       //window.draw(abeille_hexagon);
       window.draw(antshape["Ant_A1"]);
       antshape["Ant_A1"].setPosition(mappixel[5][5].x,mappixel[5][5].y);
       window.draw(antshape["Ant_A1"]);
       window.display();

   }
*/

/*
    sf::RenderWindow window({1080, 720}, "Hexagons", sf::Style::Default);

    // We're simply abusing a `CircleShape` here,
    // since a circle defined by 6 points IS a hexagon!
    sf::CircleShape hexagon(24, 6);
    sf::CircleShape selected_hexagon(24, 6);
    selected_hexagon.setOutlineThickness(2);
    selected_hexagon.setOutlineColor(sf::Color::Blue);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(2);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(-30 , 0);
    selected_hexagon.setOrigin(-30 , 0);
    //hexagon.setRotation(90);
    //selected_hexagon.setRotation(90);
    sf::Texture texture;
    if (!texture.loadFromFile("/media/sf_dossier_partage/abeille2.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (int y = 0; y < 15; ++y) {
            for (int x = 0; x < 18; ++x) {
                // The horizontal/vertical offsets of 50 and 40
                // might feel off, but that's due to the way SFML
                // calculates the circle outline
                if(y == 6 && x == 7){ selected_hexagon.setPosition((y % 2 ? 75 : 50) + x * 50.f, 50 + y * 40.f); }
                hexagon.setPosition((y % 2 ? 75 : 50) + x * 50.f, 50 + y * 40.f);
                hexagon.setFillColor(sf::Color(250, 200, 40));
                window.draw(hexagon);
                window.draw(selected_hexagon);
                window.draw(sprite);

            }
        }
        window.display();
    }*/

/*
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
*/

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