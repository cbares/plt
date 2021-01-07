#include "Test.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace client;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;
using namespace std;

void Test::state(){
    cout << "Voir tests unitaire: cd plt/build/test puis ctest" << endl;
}

void Test::render(){
    shared_ptr<State> state = make_shared<State>(10,"res/cardsData/");
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
    state->registerObserver(stateRenderer);

    while (stateRenderer->isOpen())
    {
        // Process events
        stateRenderer->update(state);
        sf::Event event;
        while (stateRenderer->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->close();
            }
    
        }
    }
}

void Test::engine(){
    shared_ptr<State> state = make_shared<State>(20,"res/cardsData/");
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
    state->registerObserver(stateRenderer);
    std::vector<std::shared_ptr<Actor>> actors;
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);

    while (stateRenderer->isOpen())
    {
        // Process events
        sf::Event event;

        stateRenderer->update(state);
        while (stateRenderer->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space){
                    std::shared_ptr<state::Player> player = state->players[state->remainingTurns%2];
                    shared_ptr<PickCommand> pickCommand = make_shared<PickCommand>(0,0,player->name);
                    engine->execute(pickCommand);
                    state->endTurn();
                }
            }
        }
    }
}

void Test::random_ai(){
    shared_ptr<State> state = make_shared<State>(200,"res/cardsData/");
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
    state->registerObserver(stateRenderer);
    std::vector<std::shared_ptr<Actor>> actors;
    actors.push_back(make_shared<RandomAI>(state->players[0]));
    actors.push_back(make_shared<RandomAI>(state->players[1]));
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);

    while (stateRenderer->isOpen())
    {
        // Process events
        sf::Event event;

        stateRenderer->update(state);
        while (stateRenderer->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space){
                    engine->step();
                }
            }
        }
    }
    engine->saveReplay("replay.json");
}

void Test::player_vs_ai(){
    shared_ptr<State> state = make_shared<State>(200,"res/cardsData/");
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
    state->registerObserver(stateRenderer);
    stateRenderer->update(state); // temp
    std::vector<std::shared_ptr<Actor>> actors;
    shared_ptr<Human> _human = make_shared<Human>(state->players[0]);
    actors.push_back(_human);
    actors.push_back(make_shared<RandomAI>(state->players[1]));
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);
    //stateRenderer->
    while (stateRenderer->isOpen())
    {
        // Process events
        sf::Event event;

        
        while (stateRenderer->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space){
                    engine->step();
                }
            }
            
            if (event.type == sf::Event::MouseButtonPressed){
		        vector<shared_ptr<render::RiverRenderer>> _riverRenderers = stateRenderer->riverRenderers;

                // Loop on rivers:
                for(uint riverpos = 0; riverpos < _riverRenderers.size(); riverpos++){
                    shared_ptr<render::RiverRenderer> _riverRenderer = _riverRenderers[riverpos];
                    // _riverRenderer is current river.
                    
                    // Loop on cards (in current river):
                    for(uint cardpos = 0; cardpos < _riverRenderer->cards.size(); cardpos++){
                        sf::Sprite _sprite = _riverRenderer->cards[cardpos]->sprite;
                        sf::Vector2f _cardPosition = _riverRenderer->cards[cardpos]->cardPosition;
                        sf::Vector2f _cardDimension = _riverRenderer->cards[cardpos]->cardDimension;

                        bool x_condition = event.mouseButton.x >= _cardPosition.x && event.mouseButton.x <= _cardPosition.x+_cardDimension.x;
                        bool y_condition = event.mouseButton.y >= _cardPosition.y && event.mouseButton.y <= _cardPosition.y+_cardDimension.y;

                        if (x_condition && y_condition){
                            cout << "hit" << endl;
                            // Clicked on that card !
                            std::shared_ptr<PickCommand> command = std::make_shared<engine::PickCommand>(riverpos, cardpos, _human->player->name);
                            _human->commandBuffer = command;

                            // Debug:
                        }
                    }
                }                
            }
        }
    }
    engine->saveReplay("replay.json");

}

void Test::heuristic_ai(){
    shared_ptr<State> state = make_shared<State>(200,"res/cardsData/");
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
    state->registerObserver(stateRenderer);
    std::vector<std::shared_ptr<Actor>> actors;
    actors.push_back(make_shared<HeuristicAI>(state->players[0]));
    actors.push_back(make_shared<HeuristicAI>(state->players[1]));
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);

    while (stateRenderer->isOpen())
    {
        // Process events
        sf::Event event;

        stateRenderer->update(state);
        while (stateRenderer->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space){
                    engine->step();
                }
            }
        }
    }
    engine->saveReplay("replay.json");
}

void Test::deep_ai(){
    shared_ptr<State> state = make_shared<State>(200,"res/cardsData/");
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
    state->registerObserver(stateRenderer);
    std::vector<std::shared_ptr<Actor>> actors;
    actors.push_back(make_shared<RandomAI>(state->players[0]));
    actors.push_back(make_shared<DeepAI>(state->players[1]));
    shared_ptr<Engine> engine = make_shared<Engine>(actors,state);

    while (stateRenderer->isOpen())
    {
        // Process events
        sf::Event event;

        stateRenderer->update(state);
        while (stateRenderer->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space){
                    engine->step();

                    stateRenderer->update(state);
                }
            }
        }
    }
    engine->saveReplay("replay.json");
}

void Test::heuristic_ai_performance(){
    const uint nbOfGames = 1000;
    uint heuristicWins =0;
    uint randomWins =0;
    for(uint i=0;i<nbOfGames;i++){
        shared_ptr<State> state = make_shared<State>(200,"res/cardsData/");
        std::vector<std::shared_ptr<Actor>> actors;
        actors.push_back(make_shared<RandomAI>(state->players[0]));
        actors.push_back(make_shared<HeuristicAI>(state->players[1]));
        shared_ptr<Engine> engine = make_shared<Engine>(actors,state);
        while(state->winnerIndex == -1){
            engine->step();
        }
        if(state->winnerIndex == 0){
            randomWins++;
            cout << "Random Wins" << endl;
        }else{
            heuristicWins++;
            cout << "Heuristic Wins" << endl;
        }
    }
    double winrate = (((double)heuristicWins)/((double)nbOfGames))*100;
    cout << "HeuristicAI win rate against RandomAI: " << winrate << "%" << endl;
}

void Test::deep_ai_performance(){
    const uint nbOfGames = 100;
    uint deepWins =0;
    uint randomWins =0;
    for(uint i=0;i<nbOfGames;i++){
        shared_ptr<State> state = make_shared<State>(200,"res/cardsData/");
        std::vector<std::shared_ptr<Actor>> actors;
        actors.push_back(make_shared<RandomAI>(state->players[0]));
        actors.push_back(make_shared<DeepAI>(state->players[1]));
        shared_ptr<Engine> engine = make_shared<Engine>(actors,state);
        while(state->winnerIndex == -1){
            engine->step();
        }
        if(state->winnerIndex == 0){
            randomWins++;
            cout << "Random Wins" << endl;
        }else{
            deepWins++;
            cout << "Deep Wins" << endl;
        }
    }
    double winrate = (((double)deepWins)/((double)nbOfGames))*100;
    cout << "DeepAI win rate against RandomAI: " << winrate << "%" << endl;
}

void Test::replay (std::string filename){
    std::vector<std::shared_ptr<Actor>> actors;
    shared_ptr<Engine> engine = make_shared<Engine>(actors,nullptr);
    
    if(engine->loadReplay(filename,"res/cardsData/") == -1){
        return;
    }
    std::shared_ptr<State> state = engine->state;

    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
    state->registerObserver(stateRenderer);

    while(stateRenderer->isOpen())
    {
        // Process events
        sf::Event event;

        stateRenderer->update(state);
        while (stateRenderer->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space){

                    engine->step();
                }
            }
        }
    }
}
