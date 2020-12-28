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
    shared_ptr<State> state = make_shared<State>(10,"res/cardsData/",rand());
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();

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
    shared_ptr<State> state = make_shared<State>(20,"res/cardsData/",rand());
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
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
    shared_ptr<State> state = make_shared<State>(200,"res/cardsData/",rand());
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
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

void Test::heuristic_ai(){
    shared_ptr<State> state = make_shared<State>(200,"res/cardsData/",rand());
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
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

void Test::heuristic_ai_performance(){
    const uint nbOfGames = 1000;
    uint heuristicWins =0;
    uint randomWins =0;
    for(uint i=0;i<nbOfGames;i++){
        shared_ptr<State> state = make_shared<State>(200,"res/cardsData/",rand());
        std::vector<std::shared_ptr<Actor>> actors;
        actors.push_back(make_shared<RandomAI>(state->players[0]));
        actors.push_back(make_shared<HeuristicAI>(state->players[1]));
        shared_ptr<Engine> engine = make_shared<Engine>(actors,state);
        while(state->winnerIndex == -1){
            engine->step();
        }
        if(state->winnerIndex == 0){
            randomWins++;
            cout << "random Wins" << endl;
        }else{
            heuristicWins++;
            cout << "heuristic Wins" << endl;
        }
    }
    double winrate = (((double)heuristicWins)/((double)nbOfGames))*100;
    cout << "HeuristicAI win rate against RandomAI: " << winrate << "%" << endl;
}

void Test::replay (std::string filename){
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();
    std::vector<std::shared_ptr<Actor>> actors;
    shared_ptr<Engine> engine = make_shared<Engine>(actors,nullptr);
    
    if(engine->loadReplay(filename,"res/cardsData/") == -1){
        return;
    }
    std::shared_ptr<State> state = engine->state;

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