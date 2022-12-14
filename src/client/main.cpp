#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.hpp>
#include <engine.hpp>
#include <render.hpp>
#include <ai.hpp>

#include <list>
#include <sstream>

#include <unordered_map>


using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

#define IterationMAX 6

int WIDTH = 1080;
int HEIGHT = 720;

int main(int argc,char* argv[]){


    if ((string)argv[argc-1]=="hello"){
        cout << "Hello World !" << endl;
    }
    else if ((string)argv[argc-1]=="engine"){

        Game game_test = *new Game();



        Player Benzema = Player("Benzema","White");
        Player Giroud =  Player("Giroud", "Black");

        std::vector<Insect*> temp3;
        std::vector<Insect*> temp4;

        Bee Bee_B2 = Bee("Bee_B2", "White", {-99,-99},0);temp4.push_back(&Bee_B2);
        Bee Bee_A2 = Bee("Bee_A2", "Black", {-99,-99},0);temp3.push_back(&Bee_A2);
        Grasshooper Grasshopper_B2 = Grasshooper("Grasshopper_B2", "White", {-99,-99},0);temp4.push_back(&Grasshopper_B2);
        Grasshooper Grasshopper_A2 = Grasshooper("Grasshopper_A2", "Black", {6,7},0);temp3.push_back(&Grasshopper_A2);
        Spider Spider_B2 = Spider("Spider_B2", "White", {7,3},0);temp4.push_back(&Spider_B2);
        Spider Spider_A2 = Spider("Spider_A2", "Black", {5,7},0);temp3.push_back(&Spider_A2);


        for(auto &i : temp4){
            Giroud.Add_Insect_Remaining(*i);
        }
        for(auto &j : temp3){
            Benzema.Add_Insect_Remaining(*j);
        }

        game_test.AppendListJoueur(Giroud);
        game_test.AppendListJoueur(Benzema);


        game_test.AppendListInsect(Bee_B2);game_test.AppendListInsect(Bee_A2);
        game_test.AppendListInsect(Grasshopper_B2);game_test.AppendListInsect(Grasshopper_A2);
        game_test.AppendListInsect(Spider_B2);game_test.AppendListInsect(Spider_A2);

        Engine engine_test = *new Engine(game_test);





        //AFFICHAGE DE LA MAP
        for (int a=0;a<game_test.GetMap()->GetLength();a++){
            for (int b=0;b<game_test.GetMap()->GetWidth();b++){
                cout <<"  ["<< game_test.GetMap()->GetListCase()[a][b].Get_i() << "|"<<game_test.GetMap()->GetListCase()[a][b].Get_j()<<"|"<<game_test.GetMap()->GetListCase()[a][b].GetEmpty()<<"]";
                if (b==game_test.GetMap()->GetWidth()-1){
                    cout<<"\n"<<endl;
                }
            }
        }


        cout<<"---------------------DEBUT DU JEU---------------------"<<endl;

        int nbTour=0;

        while (nbTour<4) {
            cout<<"---------------------TOUR N."<<nbTour <<" ---------------------"<<endl;
            cout<<"---------------------ETAT DU JEU : "<<game_test.GetState() <<" ---------------------"<<endl;

            for(auto player_test : game_test.GetListPlayer()){
                cout<<"---------------------C'EST AU TOUR DE : "<<player_test->GetName() <<" ---------------------"<<endl;
                int choix;
                int i = 0;
                int choice_x, choice_y;
                for (auto &ins: game_test.GetAllInsects()) {

                    if (ins->GetColor()==player_test->GetColor()){
                        cout << "I= " << i << " -->  " << ins->GetName() << "  |  " << ins->GetColor() << "  |  ["
                             << ins->Get_Position()[0] << ";" << ins->Get_Position()[1] << "] "<< ins->GetIsPlaced() << " \n";;
                    }
                    i++;
                }
                cout << "Choix de l'insecte à modifier :";
                cin >> i;

                while ((i > game_test.GetAllInsects().size() - 1)||(game_test.GetAllInsects()[i]->GetColor()!=player_test->GetColor())) {
                    cout << "Choix de l'insecte à placer :";
                    cin >> i;
                }
                Insect *insect_moving = game_test.GetAllInsects()[i];
                cout << "Vous avez choisi : " << insect_moving->GetName() << "\n";

                cout << "[ 0 : Placement ] ou [1 : Deplacement ]\n";
                cin >> choix;

                while ((choix != 0)&&(choix!=1)) {
                    cout << "[ 0 : Placement ] ou [1 : Deplacement ]\n";
                    cin >> choix;
                }

                vector<Case> list_case;
                for (int i=0;i<game_test.GetMap()->GetLength();i++){
                    for (int j=0;j<game_test.GetMap()->GetWidth();j++){
                        list_case.push_back( game_test.GetMap()->GetListCase()[i][j]);
                    }
                }
                vector<vector<int>> temp_coord;
                if (choix==0){
                    temp_coord = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),list_case);
                }
                else {
                    temp_coord = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),list_case);
                }

                int h=0;
                cout << "Coordonnées possibles :\n "  << endl;
                if(temp_coord.size()==0){
                    cout << "Aucunen option " << endl;
                }
                else{
                    for (auto case_temp: temp_coord) {
                        cout << "I= " << h << " -->  "  << " [" << case_temp[0] << ";" << case_temp[1] << "]\n";
                        h++;
                    }
                }

                cout << "Coordonnées ?\nx=";
                cin >> choice_x;
                cout << "y=";
                cin >> choice_y;
                cout << "Vous avez choisi : " << choix << endl;


                bool resultat;
                if (choix==0){
                    PlacementCommand plac = PlacementCommand(game_test.GetState(), {choice_x, choice_y}, *insect_moving,
                                                             PLACEMENT, *player_test,temp_coord);
                    resultat=plac.execute(engine_test);
                }
                else {
                    DeplacementCommand deplac = DeplacementCommand(game_test.GetState(), {choice_x, choice_y}, *insect_moving,
                                                             DEPLACEMENT, *player_test,temp_coord);
                    resultat=deplac.execute(engine_test);
                }




                if (resultat){cout<<"Placement effectué"<<endl;}
                else {cout<<"Placement non effectué"<<endl;
                    while(resultat==false){
                        cout << "Coordonnées ?\nx=";
                        cin >> choice_x;
                        cout << "y=";
                        cin >> choice_y;
                        cout << "Vous avez choisi : " << choix << endl;


                        PlacementCommand plac = PlacementCommand(game_test.GetState(), {choice_x, choice_y}, *insect_moving,
                                                                 PLACEMENT, *player_test,temp_coord);
                        resultat=plac.execute(engine_test);
                    }
                    cout<<"Placement effectué"<<endl;
                }


                i = 0;

                for (auto &ins: game_test.GetAllInsects()) {
                    cout << "I= " << i << " -->  " << ins->GetName() << "  |  " << ins->GetColor() << "  |  ["
                         << ins->Get_Position()[0] << ";" << ins->Get_Position()[1] << "]\n";
                    i++;
                }

                //AFFICHAGE DE LA MAP
                for (int a = 0; a < game_test.GetMap()->GetLength(); a++) {
                    for (int b = 0; b < game_test.GetMap()->GetWidth(); b++) {
                        cout << "  [" << game_test.GetMap()->GetListCase()[a][b].Get_i() << "|"
                             << game_test.GetMap()->GetListCase()[a][b].Get_j() << "|"
                             << game_test.GetMap()->GetListCase()[a][b].GetEmpty() << "]";
                        if (b == game_test.GetMap()->GetWidth() - 1) {
                            cout << "\n" << endl;
                        }
                    }
                }
                if (game_test.GetState()==Player_A_playing){
                    game_test.UpdateState(Player_B_playing);
                }
                else{
                    game_test.UpdateState(Player_A_playing);
                }

            }
            nbTour++;
        }



    }

    else if ((string)argv[argc-1]=="render"){


        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
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

        sf::Font font; //Police écriture
        if (!font.loadFromFile("./res/arial.ttf"))
            return EXIT_FAILURE;
        sf::Text text("Hello SFML", font, 20);

        for(auto &i : temp2){
            Giroud.Add_Insect_Played(*i);
        }
        for(auto &j : temp){
            Benzema.Add_Insect_Played(*j);
        }
        for(auto &i : temp4){
            Giroud.Add_Insect_Remaining(*i);
        }
        for(auto &j : temp3){
            Benzema.Add_Insect_Remaining(*j);

        }
        state.AppendListJoueur(Giroud);
        state.AppendListJoueur(Benzema);

        cout<<"AVANT"<<endl;
        cout<<state.GetListPlayer()[0]->GetName() <<"\n"<<endl;
        cout<<"APRES"<<endl;
        state.GetListPlayer()[0]->setName("RONALDO");
        cout<<state.GetListPlayer()[0]->GetName() <<"\n"<<endl;


        float X = window.getSize().x;
        float Y = window.getSize().y;
        float xo = window.getSize().x;
        float yo = window.getSize().y;

        float sx=1.0, sy=1.0;

        while (window.isOpen()) {
            int xmouse = sf::Mouse::getPosition(window).x;
            int ymouse = sf::Mouse::getPosition(window).y;



            sf::Event event;
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::Resized){
                    //sx =   float(WIDTH/window.getSize().x) ;
                    //sy =  float(HEIGHT/window.getSize().y);
                    X = (window.getSize().x);
                    Y = (window.getSize().y);
                }

                if (event.type == sf::Event::MouseButtonPressed){

                    if(event.mouseButton.button == sf::Mouse::Left){
                        //int posx = event.mouseButton.x * sx;
                        //int posy = event.mouseButton.y * sy;
                        //scene.insectDraw.getPressedInsect(posx,posy);
                        int posx = int(event.mouseButton.x * (xo/X));
                        int posy = int(event.mouseButton.y * (yo/Y));
                        //scene.insectDraw.getPressedInsect(posx,posy);
                        scene.mapDraw.getPressedTiles(posx,posy,window);
                    }
                    if(event.mouseButton.button == sf::Mouse::Right){

                        for(auto k : state.GetAllInsects()){
                            std::cout<<k->GetName()<<std::endl;
                        }

                        std::cout << "left click\n" << std ::endl;
                        std::vector<state::Player*> tempPlayer;
                        Game stateanother = state;
                        for(auto i : stateanother.GetListPlayer()){
                                for(auto j : i->Get_List_Insect_Played()){
                                        j->SetPosition({j->Get_Position()[0]+1,j->Get_Position()[1]+1});
                                    }
                                stateanother.AppendListJoueur(*i);
                            }
                        state = stateanother;
                        }
                    }
                }

            scene.drawScene(state, window);

            //int xi = int(xmouse * sx);
            //int yi = int(ymouse * sy);

            int xi = int((xmouse) * (xo/X));
            int yi = int((ymouse) * (yo/Y));

            std::stringstream ss;
            ss << "X " << xi <<"\n"
               << "Y " << yi << "\n";

            text.setString(ss.str());
            window.draw(text);
            window.display();

        }


    }

    else if ((string)argv[argc-1]=="ai") {

        Game game_test = *new Game();

        Player Benzema = Player("Benzema", "White");
        Player Giroud = Player("Giroud", "Black");

        std::vector<Insect *> temp3;
        std::vector<Insect *> temp4;
        Bee Bee_B2 = Bee("Bee_B2", "White", {-99, -99}, 0);
        temp4.push_back(&Bee_B2);
        Bee Bee_A2 = Bee("Bee_A2", "Black", {-99, -99}, 0);
        temp3.push_back(&Bee_A2);
        Grasshooper Grasshopper_B2 = Grasshooper("Grasshopper_B2", "White", {-99, -99}, 0);
        temp4.push_back(&Grasshopper_B2);
        Grasshooper Grasshopper_A2 = Grasshooper("Grasshopper_A2", "Black", {-99, -99}, 0);
        temp3.push_back(&Grasshopper_A2);
        Spider Spider_B2 = Spider("Spider_B2", "White", {-99, -99}, 0);
        temp4.push_back(&Spider_B2);
        Spider Spider_A2 = Spider("Spider_A2", "Black", {-99, -99}, 0);
        temp3.push_back(&Spider_A2);


        for (auto &i: temp4) {
            Giroud.Add_Insect_Remaining(*i);
        }
        for (auto &j: temp3) {
            Benzema.Add_Insect_Remaining(*j);
        }
        game_test.AppendListJoueur(Benzema);
        game_test.AppendListJoueur(Giroud);


        game_test.AppendListInsect(Bee_B2);
        game_test.AppendListInsect(Bee_A2);
        game_test.AppendListInsect(Grasshopper_B2);
        game_test.AppendListInsect(Grasshopper_A2);
        game_test.AppendListInsect(Spider_B2);
        game_test.AppendListInsect(Spider_A2);

        Engine engine_test = *new Engine(game_test);
        RandomAI ai_test = *new RandomAI(game_test);




        //AFFICHAGE DE LA MAP
        for (int a = 0; a < game_test.GetMap()->GetLength(); a++) {
            for (int b = 0; b < game_test.GetMap()->GetWidth(); b++) {
                cout << "  [" << game_test.GetMap()->GetListCase()[a][b].Get_i() << "|"
                     << game_test.GetMap()->GetListCase()[a][b].Get_j() << "|"
                     << game_test.GetMap()->GetListCase()[a][b].GetEmpty() << "]";
                if (b == game_test.GetMap()->GetWidth() - 1) {
                    cout << "\n" << endl;
                }
            }
        }


        cout << "---------------------DEBUT DU JEU---------------------" << endl;

        int nbTour = 0;

        while (nbTour < IterationMAX) {
            cout << "---------------------TOUR N." << nbTour << " ---------------------" << endl;


            for (auto player_test: game_test.GetListPlayer()) {

                sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",
                                        sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);


                Scene scene = Scene(game_test);

                sf::Font font; //Police écriture
                if (!font.loadFromFile("./res/arial.ttf"))
                    return EXIT_FAILURE;
                sf::Text text("Hello SFML", font, 20);
                scene.drawScene(game_test, window);
                window.display();

                if (player_test->GetColor() == "Black") {

                    vector<vector<int>> temp_coord_AI;
                    vector<int> command_list = ai_test.runAI();
                    cout<<"FIN RUN AI\n"<<endl;

                    Insect *insect_moving = game_test.GetAllInsects()[command_list[3]];
                    vector<Case> list_case;
                    for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                        for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                            list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                        }
                    }


                    if (command_list[0] == 0) {
                        cout<<"choix de placement\n"<<endl;
                        temp_coord_AI = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                                 list_case);
                        PlacementCommand plac = PlacementCommand(game_test.GetState(),
                                                                 {command_list[1], command_list[2]},
                                                                 *insect_moving,
                                                                 PLACEMENT, *player_test, temp_coord_AI);
                        bool resultat = plac.execute(engine_test);
                        if (resultat) { cout << "Placement effectué" << endl; }

                    } else {
                        cout<<"choix de déplacement\n"<<endl;
                        temp_coord_AI = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                   list_case);


                        DeplacementCommand deplac = DeplacementCommand(game_test.GetState(),
                                                                       {command_list[1], command_list[2]},
                                                                       *insect_moving,
                                                                       DEPLACEMENT, *player_test, temp_coord_AI);
                        bool resultat = deplac.execute(engine_test);
                        if (resultat) { cout << "Déplacement effectué" << endl; }
                    }

                    //AFFICHAGE DE LA MAP
                    for (int a = 0; a < game_test.GetMap()->GetLength(); a++) {
                        for (int b = 0; b < game_test.GetMap()->GetWidth(); b++) {
                            cout << "  [" << game_test.GetMap()->GetListCase()[a][b].Get_i() << "|"
                                 << game_test.GetMap()->GetListCase()[a][b].Get_j() << "|"
                                 << game_test.GetMap()->GetListCase()[a][b].GetEmpty() << "]";
                            if (b == game_test.GetMap()->GetWidth() - 1) {
                                cout << "\n" << endl;
                            }
                        }
                    }

                cout<<"FIN IA\n"<<endl;
                }

                else {


                    cout << "---------------------ETAT DU JEU : " << game_test.GetState() << " ---------------------"
                         << endl;
                    cout << "---------------------C'EST AU TOUR DE : " << player_test->GetName()
                         << " ---------------------" << endl;
                    int choix;
                    int i = 0;
                    int choice_x, choice_y;
                    for (auto &ins: game_test.GetAllInsects()) {

                        if (ins->GetColor() == player_test->GetColor()) {
                            cout << "I= " << i << " -->  " << ins->GetName() << "  |  " << ins->GetColor() << "  |  ["
                                 << ins->Get_Position()[0] << ";" << ins->Get_Position()[1] << "] "
                                 << ins->GetIsPlaced() << " \n";;
                        }
                        i++;
                    }
                    cout << "Choix de l'insecte à modifier :";
                    cin >> i;

                    while ((i > game_test.GetAllInsects().size() - 1) ||
                           (game_test.GetAllInsects()[i]->GetColor() != player_test->GetColor())) {
                        cout << "Choix de l'insecte à placer :";
                        cin >> i;
                    }
                    Insect *insect_moving = game_test.GetAllInsects()[i];
                    cout << "Vous avez choisi : " << insect_moving->GetName() << "\n";

                    cout << "[ 0 : Placement ] ou [1 : Deplacement ]\n";
                    cin >> choix;

                    while ((choix != 0) && (choix != 1)) {
                        cout << "[ 0 : Placement ] ou [1 : Deplacement ]\n";
                        cin >> choix;
                    }

                    vector<Case> list_case;
                    for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                        for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                            list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                        }
                    }
                    vector<vector<int>> temp_coord;
                    if (choix == 0) {
                        temp_coord = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                              list_case);
                    } else {
                        temp_coord = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                list_case);
                    }

                    int h = 0;
                    cout << "Coordonnées possibles :\n " << endl;
                    if (temp_coord.size() == 0) {
                        cout << "Aucunen option " << endl;
                    } else {
                        for (auto case_temp: temp_coord) {
                            cout << "I= " << h << " -->  " << " [" << case_temp[0] << ";" << case_temp[1] << "]\n";
                            h++;
                        }
                    }

                    cout << "Coordonnées ?\nx=";
                    cin >> choice_x;
                    cout << "y=";
                    cin >> choice_y;
                    cout << "Vous avez choisi : " << choix << endl;


                    bool resultat;
                    if (choix == 0) {
                        PlacementCommand plac = PlacementCommand(game_test.GetState(), {choice_x, choice_y},
                                                                 *insect_moving,
                                                                 PLACEMENT, *player_test, temp_coord);
                        resultat = plac.execute(engine_test);
                    } else {
                        DeplacementCommand deplac = DeplacementCommand(game_test.GetState(), {choice_x, choice_y},
                                                                       *insect_moving,
                                                                       DEPLACEMENT, *player_test, temp_coord);
                        resultat = deplac.execute(engine_test);
                    }


                    if (resultat) { cout << "Placement effectué" << endl; }
                    else {
                        cout << "Placement non effectué" << endl;
                        while (resultat == false) {
                            cout << "Coordonnées ?\nx=";
                            cin >> choice_x;
                            cout << "y=";
                            cin >> choice_y;
                            cout << "Vous avez choisi : " << choix << endl;


                            PlacementCommand plac = PlacementCommand(game_test.GetState(), {choice_x, choice_y},
                                                                     *insect_moving,
                                                                     PLACEMENT, *player_test, temp_coord);
                            resultat = plac.execute(engine_test);
                        }
                        cout << "Placement effectué" << endl;
                    }


                    i = 0;

                    for (auto &ins: game_test.GetAllInsects()) {
                        cout << "I= " << i << " -->  " << ins->GetName() << "  |  " << ins->GetColor() << "  |  ["
                             << ins->Get_Position()[0] << ";" << ins->Get_Position()[1] << "]\n";
                        i++;
                    }

                    //AFFICHAGE DE LA MAP
                    for (int a = 0; a < game_test.GetMap()->GetLength(); a++) {
                        for (int b = 0; b < game_test.GetMap()->GetWidth(); b++) {
                            cout << "  [" << game_test.GetMap()->GetListCase()[a][b].Get_i() << "|"
                                 << game_test.GetMap()->GetListCase()[a][b].Get_j() << "|"
                                 << game_test.GetMap()->GetListCase()[a][b].GetEmpty() << "]";
                            if (b == game_test.GetMap()->GetWidth() - 1) {
                                cout << "\n" << endl;
                            }
                        }
                    }
                    if (game_test.GetState() == Player_A_playing) {
                        game_test.UpdateState(Player_B_playing);
                    } else {
                        game_test.UpdateState(Player_A_playing);
                    }
                    cout<<"FIN JOUEUR\n"<<endl;
                }
                }
                nbTour++;
            }


        }


    else {
        cout << "It works !" << endl;
    }

    return 0;
}
