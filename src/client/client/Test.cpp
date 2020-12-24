#include "Test.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace client;
using namespace state;
using namespace render;
using namespace std;

void Test::state(){
    cout << "Voir tests unitaire: cd plt/build/test puis ctest" << endl;
}

void Test::render(){
    shared_ptr<State> state = make_shared<State>(10,"res/cardsData/");
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();

    while (stateRenderer->window.isOpen())
    {
        // Process events
        stateRenderer->update(state);
        sf::Event event;
        while (stateRenderer->window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->window.close();
            }
    
        }
    }
}

void Test::engine(){
    shared_ptr<State> state = make_shared<State>(10,"res/cardsData/");
    shared_ptr<StateRenderer> stateRenderer = make_shared<StateRenderer>();

    while (stateRenderer->window.isOpen())
    {
        // Process events
        stateRenderer->update(state);
        sf::Event event;
        /*while (stateRenderer->window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->window.close();
            }
    
        }*/
    }
}